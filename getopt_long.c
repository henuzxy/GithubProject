/*
//长参数传值是 --reqarg 100 或者 --reqarg=100这两种形式，不能使用--reqarg100
 struct option{
	const char* name;//长参数名
	int has_arg;//has_arg有三个值，用宏来传递
	//no_argument(0) 表示该参数后面无参数值
	//required_argument(1) 表示该参数后面一定要跟一个参数值
	//optional_argument(2) 表示该参数 后面可以跟参数值，也可以不跟参数值
	int* flag;
	//用来决定,getopt_long()的返回值是什么，如果flag是null，则函数会返回与该选项option匹配的value值
	//如果flag不是null,则将value值赋予flag指向的内存，并设置返回值为0
	int val;
	//用来指定函数找到选项的返回值，或者是flag非空时，指定*flag的值
 */
#include<stdio.h>
#include<getopt.h>
static struct option long_options[] = {
	{"reqarg",required_argument,NULL,'r'},
	{"optarg",optional_argument,NULL,'o'},
	{"noarg",no_argument,NULL,'n'},
	{NULL,0,NULL,0}
};

int main(int argc,char *argv[]){
	int opt;
	int digit_optind = 0;
	int option_index = 0;
	char *string = "a::b:c:d";
	while((opt = getopt_long(argc,argv,string,long_options,&option_index)) != -1){
		printf("opt = %c\t\t",opt);
		printf("optarg = %s\t\t",optarg);
		printf("optind = %d\t\t",optind);
		printf("argv[optind] = %s\t\t",argv[optind]);
		printf("option_index = %d\n",option_index);
	}

	return 0;
}
