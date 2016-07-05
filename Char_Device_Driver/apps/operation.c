#include "header.h"
int operation(int choice , int wfd,int rfd)
{
        int opt;
        switch(choice)
        {
            case 1:
                   wfd=open_device();
                   break;
            case 2:
                   printf("choice 2");
                   write_device(wfd);
                   break;
            case 3:
                   printf("choice 3");
                   read_device(rfd);
                   break;
            case 4:
                   printf("choice 4");
                   opt=ioctl_menu();
                   ioctl_device(opt);
                   break;
            case 5:
                   printf("choice 5");
                   releas_device(wfd);
                   break;
            case 6:
                   printf("choice 6");
                   exit(EXIT_SUCCESS);
                   
        }
        return wfd;
}
