#include "header.h"
int operation(int choice , int wfd)
{
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
                   releas_device(wfd);
                   break;
            case 4:
                   printf("choice 4");
                   exit(EXIT_SUCCESS);
                   
        }
        return wfd;
}
