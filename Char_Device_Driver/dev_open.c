#include "header.h"
#include "declarations.h"

struct scull_dev *ldev;

int dev_open(struct inode *inodep,struct file *filp)
{  
    int ret; 
    printk(KERN_INFO "Inside dev_open");
    ldev=dev;
    ldev=container_of(inodep->i_cdev,struct scull_dev,cdev);
    if(!ldev)
    {
         printk(KERN_ERR "ldev not valid dev_open");
    }
    filp->private_data=ldev;
    if((filp->f_flags & O_ACCMODE)==O_WRONLY)
    {
         ret=trim_dev(ldev);
         if (ret <0)
         {
              printk(KERN_ERR "trim_dev");
         }
    }
    printk(KERN_INFO "Leaving dev_open");
     return 0;
}
