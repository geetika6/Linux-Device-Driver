#include "header.h"

int read_device()
{
      char buffer[BUFFER_SIZE];
      int fd,count;
      printf("enter read\n");
      fd=open(NODE,O_RDONLY);
      count=read(fd,buffer,BUFFER_SIZE);

      printf("data read= %s =\n",buffer);
      printf("count of data read= %d =\n",count);
      	
      printf("exit read  \n");
      return 0;
}

