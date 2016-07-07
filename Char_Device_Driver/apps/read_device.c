#include "header.h"

int read_device(int rfd)
{
      char buffer[BUFFER_SIZE];
      int count,origin,offset,choice,fpos;
      printf("enter read\n");
      
      rfd=open(NODE,O_RDONLY);
      printf("if there is a seek req enter 1 else enter 0 \n");
      scanf("%d",&choice);
      if (choice==1)
      { 
          printf("enter offset=\n");
          scanf("%d",&offset);
          printf("enter origin=\n");
          scanf("%d",&origin);
          fpos=seek_device(rfd,offset,origin);
          printf("final position= %d \n",fpos);
           count=read(rfd,buffer,BUFFER_SIZE);
           printf("data read= %s =\n",buffer);
           printf("count of data read= %d =\n",count);
      }
      else if (choice==0)
      {	
           count=read(rfd,buffer,BUFFER_SIZE);
           printf("data read= %s =\n",buffer);
           printf("count of data read= %d =\n",count);
      }

      printf("exit read  \n");
      return 0;
}

