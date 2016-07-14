#include "header.h"

int write_device(int wfd)
{
      int count,origin,offset,choice,fpos;
      char buffer[BUFFER_SIZE]="this is geetika arora driver, i am happy to make my driver";
     //char buffer1[BUFFER_SIZE]="this is geetika arora driver, i am sad to make my driver";
      char buffer1[BUFFER_SIZE]="FGHLASKDOA";
      printf("enter write\n");
      printf("if there is a seek req enter 1 else enter 0 \n");
      scanf("%d",&choice);
      if (choice==1)
      { 
          printf("enter offset=\n");
          scanf("%d",&offset);
          printf("enter origin=\n");
          scanf("%d",&origin);
          fpos=seek_device(wfd,offset,origin);
          printf("final position= %d \n",fpos);
          //count=write(wfd,buffer,strlen(buffer));
          count=write(wfd,buffer1,strlen(buffer1));
          printf("count of data written = %d =\n",count);
      }
      else if (choice==0)
      {	
          count=write(wfd,buffer,strlen(buffer));
          printf("count of data written= %d =\n",count);
      }
      	
      printf("enter write count =%d \n",count);
      printf("exit write  \n");
      return 0;
}

