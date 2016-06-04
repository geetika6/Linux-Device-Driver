#include "header.h"

int write_device(int wfd)
{
      char buffer[BUFFER_SIZE]={0};
      printf("enter write\n");
      write(wfd,buffer,strlen(buffer));
      	
      printf("exit write  \n");
      return 0;
}

