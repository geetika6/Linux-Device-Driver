#include "header.h"

int releas_device(int wfd)
{
      printf("enter release\n");
      close(wfd);	
      printf("exit release \n");
      return 0;
}

