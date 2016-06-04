#include "header.h"
#include "declarations.h"


int dev_release(struct inode *inodep,struct file *filp)
{   
    printk(KERN_INFO "Inside dev_release");
    printk(KERN_INFO "Leaving dev_release");
     return 0;
}
