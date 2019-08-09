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


