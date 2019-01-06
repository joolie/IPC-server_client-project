#include"header.h"
#include"mydatatype.h"
#include"declaration.h"
result invokedprocessingclient(request r,int* pipes)
{
	result d;
	int ret;
	int ec;
	printf("%s:Begin\n",__FILE__);
	char rfd[4];
	char wfd[4];
	sprintf(rfd,"%d",*(pipes+4));
        sprintf(wfd,"%d",*(pipes+7));
//	write(*(pipes+5));
	ret=fork();
        switch(ret)
	{
		case -1:
			perror("fork");
			exit(EXIT_FAILURE);
		case 0:
			
        switch(r.oper)
        {
                case '+':

        		write(*(pipes+5),&r,sizeof(request));
                        execl("./add","add",rfd,wfd,NULL);
			
                case '-':
                        execl("./sub","sub",rfd,wfd,NULL);

                case '*':
                        execl("./mul","mul",rfd,wfd,NULL);
                
                case '/':
                        execl("./div","div",rfd,wfd,NULL);
		default:
                        printf("defalut operator");
	}
		default :

		        wait(&ec);
        		read(*(pipes+6),&d,sizeof(d));
			printf("d.res=%d\n",d.res);
        
	}
	printf("%s:End\n",__FILE__);
	return d;
}
