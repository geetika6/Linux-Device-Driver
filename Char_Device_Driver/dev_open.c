#include "header.h"
#include "declarations.h"


int dev_open(struct inode *inodep,struct file *filep)
{   
    printk(KERN_INFO "Inside dev_open");
    printk(KERN_INFO "Leaving dev_open");
     return 0;
}
