### select 的IO复用技术慢的原因
- 1.每次调用select函数后，要针对所有文件描述符扫描一遍，判断是哪个文件描述符发生了变化.
- 2.每次调用select前后需要向该函数重新传递一遍监视对象信息。往往需要把监视对象信息拷贝一份，因为调用select后会清空。

第2种的负担更大，因为每次调用select都需要向操作系统传递数据。套接字时由操作系统管理的，所以监视套接字的变化，必须要借助操作系统才能完成。

### select的优点
- 兼容性好，大多数操作系统都提供该函数。windows,Linux.
在服务端接入较少和要求程序兼容性高的时候，可以使用select.

### epoll的优点
- 1.不需要对所有文件描述符扫描一遍，来判断是否发生变化。
- 2.调用epoll\_wait函数时，无需每次传递监视对象.
### epoll服务端需要的函数和结构体

int epoll\_create(int size);

创建保存epoll文件描述符的空间.成功时返回epoll文件描述符，失败时返回-1.
调用epoll\_create函数创建的文件描述符保存空间称为 "epoll例程".
通过参数size传递的值决定epoll例程的大小，但该值只是向操作系统提出的建议。即仅供操作系统参考.
> Linux 2.6.8之后的内核完全忽略传入的size，因为内核会根据情况调整epoll例程的大小,cat /proc/sys/kernel/osrelease 可以查看Linux版本

int epoll\_ctl(int epfd,int op,int fd,struct epoll\_event \*event);

**成功时返回0，失败时返回-1.**
- epfd:用于注册监视对象的epoll例程的文件描述符.
- op:用于指定监视对象的添加、删除或更改等操作.
   - EPOLL\_CTL\_ADD:将文件描述符注册到epoll例程.
   - EPOLL\_CTL\_DEL:从epoll例程中删除文件描述符.
   - EPOLL\_CTL\_MOD:更改注册的文件描述符的关注事件发生情况.
- fd:需要注册的监视对象文件描述符.
- event:监视对象的事件类型.

int epoll\_wait(int epfd,struct epoll\_event \* events,int maxevents,int timeout);
**成功时返回发生事件的文件描述符的数目，失败时返回-1**

该函数作用与select类似，等待文件描述符发生变化

---

在select方式中，需要声明fd\_set变量.但在epoll方式下操作系统负责保存监视对象文件描述符.
在epoll方式下,通过结构体epoll\_event将发生变化的文件描述符单独集中到一起.
```c
struct epoll_event{
    __unint32_t events;
    epoll_data_t data;
}

typedef union epoll_data{
    void * ptr;
    int fd;
    __uint32_t u32;
    __uint64_t u64;
}epoll_data_t;
```
声明足够大的epoll\_event结构体数组后，传递给epoll\_wait函数，发生变化的文件描述符信息就会被填入该数组.无需向select一样要循环扫描一遍所有注册的文件描述符.

epoll\_event的成员events中可以保存的常量及所指的事件类型有如下:
- EPOLLIN:需要读取数据的情况.
- EPOLLOUT:输出缓冲为空，可以立即发送数据的情况.
- EPOLLPRI:收到OOB数据的情况.
- EPOLLRDHUP:断开或半关闭情况
- EPOLLERR:发生错误的情况.
- EPOLLET:以边缘触发的方式得到事件通知.
### 条件触发和边缘触发
条件触发方式中，只要输入缓冲有数据就会一直通知该事件.
如:服务器端输入缓冲收到50 bytes数据，服务器端操作系统会注册到发生变化的文件描述符里。但服务器端读取20 bytes后还剩下30 bytes,仍会注册该事件.即只要输入缓冲有数据，就会将事件再次注册.
相对应的,边缘触发中输入缓冲收到数据时仅注册一次该事件.即使没有读取完，也不会再次注册.
**epoll默认是条件触发方式,select模型也是条件触发的方式工作的**

实现边缘触发:
- 通过errno变量验证错误原因.
- 更改套接字，使用非阻塞IO.
> read()函数发现输入缓冲中没有数据可以读时返回-1，同时在errno中保存EAGAIN常量.
更改套接字为非阻塞的方法

```c
#include<fcntl.h>
int fcntl(int filedes,int cmd,...);
//成功时返回cmd参数相关值，失败时返回-1.
```
- filedes:更改目标的文件描述符
- 表示函数调用的目的
```c
int flag = fcntl(fd,F_GETFL,0);//获得fd的属性
fcntl(fd,F_SETFL,flag|O_NONBLOCK);//在原有基础上添加非阻塞O_NONBLOCK标志。
```

### 套接字

套接字是操作系统提供的，可以理解为网络数据传输用的软件设备。

socket();//创建套接字

bind();//对套接字分配IP和port

listen();//可以接受请求连接,这里可以设置最大连接数

accept();//开始受理请求。

#### 协议族

| 名称      | 协议族               |
| --------- | -------------------- |
| PF_INET   | IPV4互联网协议族     |
| PF_INET6  | IPV6互联网协议族     |
| PF_LOCAL  | 本地通信的UNIX协议族 |
| PF_PACKET | 底层套接字的协议族   |
| PF_IPX    | IPX Novell协议族     |

#### 套接字类型

##### 面向连接的套接字(TCP) SOCK_STREAM

- 传输过程中数据不会消失
- 按序传输数据
- 传输的数据不存在数据边界

不存在数据边界，例如调用3次write,但可以通过1次read即全部接收。

套接字缓冲已满是否意味着数据丢失？

套接字内部存在一个由字节数组构成的缓冲(默认为8K)，当缓冲被填满时，套接字无法再接收数据,这样不会导致数据丢失，因为传输套接字会停止传输。面向连接的套接字会根据接收端的状态传输数据，如果传输出错会再次传输。

##### 面向消息的套接字(UDP) SOCK_DGRAM

- 强调快速传输而非传输顺序
- 传输的数据可能丢失也可能损坏
- 传输的数据有数据边界。
- 限制每次传输的数据大小

SOCKET的第三个参数可以具体指定协议信息，因为存在这种情况:“同一协议族中存在多个数据传输方式相同的协议”。

#### 字节序和网络字节序

- 大端序：高位字节存放到低位地址
- 小端序：高位字节存放到高位地址

对于一个整数0x12345678

Ox 12 34 56 78 即为大端序，0x 78 56 34 12即为小端序。用union可以验证自己电脑的字节序

```cpp
union A{
    unsigned int value;
    char ch[sizeof(value)];
};
A t;
t.value = 0x12345678;//输出ch对应的16进制即可。
```

#### UDP的特点

UDP不会发送类似ACK的应答包，也不会像SEQ那么样给数据包分配序列号

UDP 具有流控制。

TCP套接字默认使用Nagle算法交换数据，因此最大限度的进行缓冲，知道收到ACK。禁用Nagle算法时的发送过程与ACK接受与否无关，因此数据到达输出缓冲后将立即被发送出去。但不使用Nagle算法会导致网络负载。

#### 基于Windows的I/O函数

在Linux中套接字也是文件，因而可以通过文件I/O函数read和write进行数据传输。而Windows中则有些不同。Windows严格区分文件IO和套接字IO,

```cpp
#include<winsock2.h>
int send(SOCKET s,const char *buf,int len,int flags);
//成功时返回传输字节数，失败时返回SOCKET_ERROR
```

- s 表示数据传输对象连接的套接字句柄值
- buf 保存待传输数据的缓冲地址值
- len 表示要传输的字节数
- flags 表示传输数据时用到的多种选项信息

```cpp
#include<winsock2.h>
int recv(SOCKET s,constr char *buf,int len,int flags);
//成功时返回接收的字节数(收到EOF时为0),失败时返回SOCKET_ERROR
```

- s 表示数据接收对象连接的套接字句柄值
- buf 保存接收数据的缓冲池地址值
- len 能够接收的最大字节数
- flags 接收数据时用到的多种选项信息。

