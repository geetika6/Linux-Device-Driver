#include "header.h"
#include "declarations.h"

struct scull_dev *gdev;

int dev_open(struct inode *inodep,struct file *filp)
{  
    int ret; 
    printk(KERN_INFO "Inside dev_open");
    gdev=dev;
    gdev=container_of(inodep->i_cdev,struct scull_dev,cdev);
    if(!gdev)
    {
         printk(KERN_ERR "gdev not valid dev_open");
    }
    filp->private_data=gdev;
    if(((filp->f_flags & O_ACCMODE)==O_WRONLY) && gdev->sqset!=NULL)
    {
         if (down_interruptible(&gdev->sem))
		return -ERESTARTSYS;
         ret=trim_dev(gdev);
         if (ret <0)
         {
              printk(KERN_ERR "trim_dev");
         }
         up(&gdev->sem);
    }
 
    printk(KERN_INFO "Leaving dev_open");
     return 0;
}
