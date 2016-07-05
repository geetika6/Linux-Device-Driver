#include "header.h"

int write_device(int wfd)
{
      int count;
      char buffer[BUFFER_SIZE]="this is geetika arora driver, i am happy to make my driver";
      printf("enter write\n");
      count=write(wfd,buffer,strlen(buffer));
      	
      printf("enter write count =%d \n",count);
      printf("exit write  \n");
      return 0;
}

