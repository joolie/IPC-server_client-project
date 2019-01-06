#include"header.h"
#include"mydatatype.h"
#include"declaration.h"
int main(int argc,char* argv[])
{
	request r;
	result a;
	int wfd,rfd;
	printf("%s:Begin\n",__FILE__);
	rfd = atoi(argv[1]);
        wfd = atoi(argv[2]);
	read(rfd,&r,sizeof(request));
	printf("r.opr1=%d\nr.opr2=%d\nr.oper=%c\n",r.opr1,r.opr2,r.oper);
        a.res=r.opr1+r.opr2;
	printf("a.res=%d\n",a.res);
	a.pid=getpid();
       	write(wfd,&a,sizeof(result));
	printf("a.res=%d\n",a.res);
	printf("%s:End\n",__FILE__);

}
