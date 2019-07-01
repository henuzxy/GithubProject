#include<stdio.h>

int main(int argc,char *argv[]){
	/*
		stdout(标准输出),输出方式是行缓冲，输出的字符会先放到缓冲区，等按下回车时才执行IO操作。
		stderr(标准错误),不带缓冲，直接输出。

	   */
	/*
	   这里会先输出henuzxy
	fprintf(stdout,"Group");
	fprintf(stderr,"henuzxy");
	*/
	/*
	   这里会先输出Group
	fprintf(stdout,"Group\n");
	fprintf(stderr,"henuzxy");
	*/

	fprintf(stdout,"Group\n");
	fprintf(stderr,"henuzxy\n");
	return 0;
}
