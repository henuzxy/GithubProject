#include<stdio.h>
#include<unistd.h>

int main(int argc,char *argv[]){
	int opt;
	char *str = "a::b:c:d";
	/*
	   a::表示a后面可以有参数也可以无参数，但形式必须是 -a100
	   b:表示 b后面必须有参数，形式可以是 -b100 或 -b 100
       c:和b一样
	   d 表示d后面不能有参数。
	
	 
	 */
	while((opt = getopt(argc,argv,str)) != -1){
		printf("opt = %c\t\t",opt);
		printf("optarg = %s\t\t",optarg);
		printf("argv[optind] = %s\n",argv[optind]);
	}
	return 0;
}
