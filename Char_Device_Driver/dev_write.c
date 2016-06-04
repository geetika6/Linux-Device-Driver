#include "header.h"
#include "declarations.h"


ssize_t dev_write(struct file *filp,const char __user *ubuff,size_t count,loff_t *loff)
{  
    struct scull_dev *ldev;
    printk(KERN_INFO "Inside dev_write");
    ldev=NULL;
    //since private data was of void type
    ldev =(struct scull_dev *)filp->private_data;
    if(!ldev)
    {
         printk(KERN_ERR "dev not found");
         goto OUT;
    }
    printk(KERN_INFO "Leaving dev_write");
     return 0;
OUT:
     return -7;
}
