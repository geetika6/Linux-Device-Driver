#include "header.h"

int seek_device(int fd,off_t offset,int origin)
{
      off_t fpos;
      printf("enter seek\n");
      fpos=lseek(fd,offset,origin);

      printf("exit seek  \n");
      return fpos;
}

