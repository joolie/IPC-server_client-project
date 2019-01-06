#include"header.h"
#include"mydatatype.h"
#include"declaration.h"
int* creatinfra()
{ 
	int i;
	int *pipes;
	pipes=(int *)malloc(8);
	printf("%s:Begin\n",__FILE__);
	for(i=0;i<8;i+=2)
	{
         pipe(pipes+i);
	}
	printf("%s:End\n",__FILE__);
	return pipes;
}
