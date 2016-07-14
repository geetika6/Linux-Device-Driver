#include "header.h"
#include "declarations.h"
#include "file_opr.h"

dev_t dev_id,dev_no;
int majorno,minorno;
int devicesize,datasize,quantumsize,qsetsize;
int ret;
int nod=1;
int minorno=0;
//struct scull_dev *dev;
struct scull_dev *dev;

//const struct file_operations *fops={};
//const struct file_operations *fops;
int err=0;
module_param(nod,int,0);	
static int __init start_module(void)
{   
    int i=0;
    devicesize=DEVICESIZE;
    datasize=DATASIZE;
    qsetsize=QSETSIZE;
    quantumsize=QUANTUMSIZE;
    printk(KERN_INFO "Hello world \n");
    ret=alloc_chrdev_region(&dev_id,minorno,nod,DEVNAME);
    majorno=MAJOR(dev_id);
    printk(KERN_INFO "major dev_id = %d",majorno);
    if (ret<0)
    {   
	printk(KERN_ALERT "alloc_chrdev_region not successful");
        goto OUT;
    }
    dev=kmalloc(nod*sizeof(struct scull_dev),S_IRUGO);
    if (dev==NULL)
    {   
	printk(KERN_ALERT "kmalloc not successful");
        goto OUT;
    }
    memset(dev, 0, sizeof(struct scull_dev)*nod);
    //for(i=0;i++;i<nod)
    while(i<nod)
    {    
         dev_no=MKDEV(majorno,i);
         //struct cdev *my_cdev=cdev_alloc();
         cdev_init(&(dev[i].cdev),&fops);
         dev[i].cdev.owner=THIS_MODULE;
         dev[i].cdev.ops=&fops;
         dev[i].devicesize=devicesize;
         dev[i].datasize=datasize;
         dev[i].qsetsize=qsetsize;
         dev[i].quantumsize=quantumsize;
         printk(KERN_INFO "minor dev_id = %d",i);
         printk(KERN_INFO "add of dev[i] = %p",dev+i);
         //init_MUTEX(&devices[i].sem);
         sema_init(&dev[i].sem,1);
         err=cdev_add(&dev[i].cdev,dev_no,nod);
         if (err<0)
         {   
             printk(KERN_ALERT "cdev_add not successful for dev_id=%d ",dev_id);
             goto OUT;
         }
         i=i+1;
    }
     return 0;
OUT: return -1;   
}
module_init(start_module);
