#include "header.h"
#include "declarations.h"
#include "ioctl.h"
long dev_ioctl(struct file *filp,unsigned int cmd,unsigned long arg)
{  
    struct scull_dev *ldev;
    int i;
    printk(KERN_INFO "Inside dev_ioctl");
    ldev =(struct scull_dev *)filp->private_data;
    if (!ldev)
    {
         printk(KERN_ERR "Error in ioctl dev acquisition");
    }
    switch(cmd)
    {
        case RESETDEVICE:
             ldev->quantumsize=QUANTUMSIZE; 
             ldev->qsetsize=QSETSIZE; 
             ldev->datasize=DATASIZE;
             break; 
        case GETREGSIZE:
             printk(KERN_INFO "reg size in driver=%d",ldev->quantumsize);
             put_user(ldev->quantumsize,(int __user*)arg);
             printk(KERN_INFO "arg pointer in get reg size=%p",&arg);
             printk(KERN_INFO "arg value in get reg size=%ld",arg);
             //copy_to_user(&arg,(const void *)ldev->quantumsize,4);
             break; 
        case GETNOREG:
             put_user(ldev->qsetsize,(int __user*)arg);
             break; 
        case GETDATASIZE:
             put_user(ldev->datasize,(int __user*)arg);
             break; 
        case SETREGSIZE:
             printk(KERN_INFO "ioctl reg size =%d",ldev->quantumsize);
             get_user(ldev->quantumsize,(int __user *)arg);
             printk(KERN_INFO "ioctl arg size =%ld",arg);
             printk(KERN_INFO "ioctl arg pointer =%p",&arg);
             printk(KERN_INFO "New reg size =%d",ldev->quantumsize);
             break; 
        case SETNOREG:
             get_user(ldev->qsetsize,(int __user*)arg);
             printk(KERN_INFO "New no of reg  =%d",ldev->qsetsize);
             break; 
    }
    
    printk(KERN_INFO "Leaving dev_open");
    return 0;
}
