#include <stdio.h>
#include <unistd.h>

void main()
{

	int first=2;
	int second=4;
	pid_t pid;
	int final=first + second;
	printf("value of first=%d\n",first);
	printf("value of second=%d\n",second);
	pid=fork();
	if (pid==0)
	{
		printf("child process=%d\n",getpid());
	}
        else
        {
		printf("parent process=%d\n",getpid());
        }
	printf("value of final=%d\n",final);

}
