#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#define NODE "/root/modules/node"
#define BUFFER_SIZE 100
extern int wfd;

int open_device ();
int write_device (int);
int read_device ();
int releas_device (int);
int operation (int,int);
