#include"header.h"
#include"mydatatype.h"
#include"declaration.h"
result processrequest(request r,int *pipes)
{  
	int ec;
	result ro;
	int re;
	printf("%s:Begin\n",__FILE__);
	re = fork();
	switch(re)
	{
		case 1:
			printf("process request error\n");
			exit(EXIT_FAILURE);
		case 0:
			ro = (*invoprocl)(r,pipes);
			printf("return value=%d\n",ro.res);
			
		default :
			wait(&ec);
			printf("procesreq\n");

	}

	printf("%s:End\n",__FILE__);
	return ro;
	
}
