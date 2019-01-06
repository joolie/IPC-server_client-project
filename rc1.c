#include"header.h"
#include"mydatatype.h"
#include"declaration.h"
int main(int argc , char *argv[])
{ 
	request r;
	result a;
	int wfd,rfd,count,cou;
	printf("%s:Begin\n",__FILE__);
	r.pid = getpid();
	r.oper='+';
	r.opr1=33;
	r.opr2=22;
	if(argc != 3)
	{
		printf("argc error");
		exit(EXIT_FAILURE);
	}
	wfd = atoi(argv[1]);
	rfd = atoi(argv[2]);
        count= write(wfd,&r,sizeof(request));
	if(count==-1)
	{
		perror("write");
		exit(EXIT_FAILURE);
	}
	cou=read(rfd,&a,sizeof(result));
	printf("checking....\n");
	printf("write=%d\n",count);
	printf("read=%d\n",cou);
	printf("Result=%d\n",a.res);
	printf("%s:End\n",__FILE__);
	return 0;
}


