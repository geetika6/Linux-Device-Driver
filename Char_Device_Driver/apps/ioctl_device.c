#include "header.h"
#include "ioctl.h"

int ioctl_device(int choice)
{
      int rfd,wfd;
      int arg;
      switch(choice)
      { 
          case 1:
                rfd=open(NODE,O_RDONLY);
                ioctl(rfd,RESETDEVICE);
                printf("the device is reset to its initial settings\n");
                break;
          case 2:
                rfd=open(NODE,O_RDONLY);
                ioctl(rfd,GETREGSIZE,&arg);
                printf("the reg size in device = %d\n",arg);
                break;
          case 3:
                rfd=open(NODE,O_RDONLY);
                ioctl(rfd,GETNOREG,&arg);
                printf("the no of reg in device = %d\n",arg);
                break;
          case 4:
                wfd=open(NODE,O_WRONLY);
                printf("enter the new reg size to be set\n");
                scanf("%d",&arg);
                ioctl(wfd,SETREGSIZE,&arg);
                break;
          case 5:
                wfd=open(NODE,O_WRONLY);
                printf("enter the no of reg to be set\n");
                scanf("%d\n",&arg);
                ioctl(wfd,SETNOREG,&arg);
                break;
      }	
      return 0;
}


