#include "header.h"
int rfd;
int main()
{
	int choice,wfd;
        choice=0;
	printf("choice 1 is open device \n ");
	printf("choice 2 is write device \n");
	printf("choice 3 is read device \n");
	printf("choice 4 is ioctl device \n");
	printf("choice 5 is release device \n");
	printf("choice 6 EXIT \n");
        while(1)
        {
	     printf("enter choice=\n");
             scanf("%d",&choice);
             wfd=operation(choice,wfd,rfd);
            // i++;
        }
        return 0;
}
