#include"header.h"
#include"mydatatype.h"
#include"declaration.h"
int main()
{
	request r;
	result re;
	int ret,count;
	int *pipes;
	int value;
	char clwrtfd[4];//int size 4byte convert into string
	char clrdfd[4];
	printf("%s:Begin\n",__func__);
	init();
	pipes = (*crin)();
	if(!pipes)
	{
		perror("pipe");
		free(pipes);
		exit(EXIT_FAILURE);
	}
	ret= fork();
	switch(ret)
	{
		case -1: 
			perror("fork");
			exit(EXIT_FAILURE);
		case 0:
			sprintf(clwrtfd,"%d",*(pipes+1));
			sprintf(clrdfd,"%d",*(pipes+2));
			execl("./rc1","rc1",clwrtfd,clrdfd,NULL);
			break;
			
		default:
                        printf("processing client\n");
			count= read(*(pipes+0),&r,sizeof(request));
			printf("read=%d\n",count);
			re=(*prores)(r,pipes);
			write(*(pipes+3),&re,sizeof(result));
			printf("res=====%d\n",re.res);
	}
	printf("%s:End\n",__func__);
	return 0;
}
