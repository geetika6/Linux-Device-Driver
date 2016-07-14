#include "header.h"
int ioctl_menu()
{
	int choice;
	printf("choice 1 is reset device \n ");
	printf("choice 2 is get reg size in device \n");
	printf("choice 3 is get no of reg in device \n");
	printf("choice 4 is get size of data in bytes \n");
	printf("choice 5 is set reg size in device \n");
	printf("choice 6 is set no of reg in device \n");
	printf("enter choice=\n");
        scanf("%d",&choice);
        return choice;
}
