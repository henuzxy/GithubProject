/*************************************************************************
	> File Name: webbench.c
	> Author:henuzxy 
	> Mail: 
	> Created Time: 2019年07月22日 星期一 17时20分13秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<sys/param.h>
#include<rpc/types.h>
#include<getopt.h>
#include<strings.h>
#include<time.h>
#include<signal.h>
#include<string.h>
#include<error.h>

static void Usage(void){
    char useinfo[] =
        "webbench [选项参数]...URL\n"
        "-f\t --force\t\t\t不用等待服务器响应\n"
        "-r\t --reload\t\t\t重新请求加载(无缓存)\n"
        "-t\t --time <sec>\t\t\t运行时间，单位：秒，默认为30秒\n"
        "-p\t --proxy <IP:Port>\t\t使用代理服务器发送请求\n"
        "-c\t --clients <num>\t\t创建客户端个数,默认为1\n"
        "-9\t --http09\t\t\t使用http0.9协议\n"
        "-1\t --http10\t\t\t使用http1.0协议\n" 
        "-2\t --http11\t\t\t使用http1.1协议\n"
        "\t --get\t\t\t\tGET请求方式\n"
        "\t --head\t\t\t\tHEAD请求方式\n"
        "\t --options\t\t\tOPTIONS请求方式\n"
        "\t --trace\t\t\tTRACE请求方式\n"
        "-?|-h\t --help\t\t\t\t显示帮助信息\n"
        "-v\t --version\t\t\t显示版本信息\n"
    ;
    fprintf(stderr,"%s",useinfo);
}
/*http请求方法的相关宏定义*/
#define METHOD_GET (0)
#define METHOD_HEAD (1)
#define METHOD_OPTIONS (2)
#define METHOD_TRACE (3)

/*代码相关的宏定义*/
#define bool char
#define true (1)
#define false (0)

/*相关参数与其默认值*/
int method = METHOD_GET;
int clients = 1;
bool force = false;
bool reload = false;
int port = 80;
char* proxyhost = NULL;//默认不使用代理
int bench_time = 30;
int http = 1;//http协议版本，0:http0.9 1:http1.0 2:http1.1

/*进程管道*/
int pipe[2];


int main(int argc,char* argv[]){
    Usage();

    return 0;
}
