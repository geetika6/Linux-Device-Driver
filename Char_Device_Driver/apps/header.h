#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/ioctl.h>
#define NODE "/root/modules/node"
#define BUFFER_SIZE 100
extern int wfd;

int open_device ();
int write_device (int);
int read_device (int);
int releas_device (int);
int ioctl_device (int);
int operation (int,int,int);
int seek_device (int,off_t,int);
