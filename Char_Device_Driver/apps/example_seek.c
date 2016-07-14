#include "header.h"

int main()
{
      int fd,origin;
      int fpos,offset;
      char buffer[10]="this is GA";
      char buffer1='R';
      char buffer2='2';
      char buffer3='3';
      char buffer4='4';
      printf("enter seek\n");
      fd=open("name",O_WRONLY);
       //   printf("enter offset=\n");
        //  scanf("%d",&offset);
         // printf("enter origin=\n");
          //scanf("%d",&origin);
      //fpos=lseek(fd,offset,origin);
      write(fd,&buffer,strlen(buffer));
     perror("write");
      //fpos=lseek(fd,offset,origin);
      write(fd,&buffer1,sizeof(char));
     perror("write1");
      write(fd,&buffer2,sizeof(char));
     perror("write2");
      write(fd,&buffer4,sizeof(char));
     perror("write4");
      write(fd,&buffer3,sizeof(char));
     perror("write3");
          printf("enter offset=\n");
          scanf("%d",&offset);
          printf("enter origin=\n");
          scanf("%d",&origin);
      fpos=lseek(fd,offset,origin);
      write(fd,&buffer,sizeof(buffer));
      printf("fpos=%d\n",fpos);

          printf("enter offset=\n");
          scanf("%d",&offset);
          printf("enter origin=\n");
          scanf("%d",&origin);
      fpos=lseek(fd,offset,origin);
      read(fd,&buffer,sizeof(buffer));
      printf("buffer=%s\n",buffer);
      printf("fpos=%d\n",fpos);
      printf("exit seek  \n");
      return fpos;
}


