#include "header.h"
#include "declarations.h"
#include "ioctl.h"
long dev_ioctl(struct file *filp,unsigned int cmd,unsigned long arg)
{  
    struct scull_dev *ldev;
    int i;
    printk(KERN_INFO "Inside dev_ioctl");
    ldev =(struct scull_dev *)filp->private_data;
    switch(cmd)
    {
        case RESETDEVICE:
             ldev->quantumsize=QUANTUMSIZE; 
             ldev->qsetsize=QSETSIZE; 
             ldev->datasize=DATASIZE;
             break; 
        case GETREGSIZE:
             printk(KERN_INFO "reg size in driver=%d",ldev->quantumsize);
             put_user(ldev->quantumsize,&arg);
             break; 
        case GETNOREG:
             put_user(ldev->qsetsize,&arg);
             break; 
        case SETREGSIZE:
             get_user(ldev->quantumsize,&arg);
             printk(KERN_INFO "New reg size =%d",ldev->quantumsize);
             break; 
        case SETNOREG:
             get_user(ldev->qsetsize,&arg);
             printk(KERN_INFO "New no of reg  =%d",ldev->qsetsize);
             break; 
    }
    
    printk(KERN_INFO "Leaving dev_open");
    return 0;
}
