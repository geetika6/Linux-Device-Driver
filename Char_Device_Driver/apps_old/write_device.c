#include "header.h"

int write_device(int wfd)
{
      char buffer[BUFFER_SIZE]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};
      printf("enter write\n");
      write(wfd,buffer,strlen(buffer));
      	
      printf("exit write  \n");
      return 0;
}

