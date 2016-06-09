#include "header.h"

int write_device(int wfd)
{
      char buffer[BUFFER_SIZE]="this is geetika arora driver, i am happy to make my driver";
      printf("enter write\n");
      write(wfd,buffer,strlen(buffer));
      	
      printf("exit write  \n");
      return 0;
}

