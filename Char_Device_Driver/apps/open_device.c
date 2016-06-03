#include "header.h"

int open_device()
{
      int fd;
      fd=open(NODE,O_WRONLY);
      	
      perror("open_device");
      return fd;
}


