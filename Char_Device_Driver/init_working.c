#include "header.h"
#include "declarations.h"

dev_t dev_id;
int majorno,minorno;
int ret;
int nod=1;
struct scull_dev *dev;
//const struct file_operations *fops={};
const struct file_operations *fops;
int err=0;
static int __init start_module(void)
{
    printk(KERN_INFO "Hello world \n");
    ret=alloc_chrdev_region(&dev_id,minorno,nod,DEVNAME);
    majorno=MAJOR(dev_id);
    printk(KERN_INFO "major dev_id = %d",majorno);
    if (ret<0)
    {   
	printk(KERN_ALERT "alloc_chrdev_region not successful");
        goto OUT;
    }
    dev=kmalloc(sizeof(struct scull_dev),S_IRUGO);
    if (dev==NULL)
    {   
	printk(KERN_ALERT "kmalloc not successful");
        goto OUT;
    }
    memset(dev, 0, sizeof(struct scull_dev));
   // for(int i=0;i++;i<nod)
   // {    
         //dev_no=MKDEV(majorno,minorno);
         //struct cdev *my_cdev=cdev_alloc();
         cdev_init(&dev->cdev,fops);
         dev->cdev.owner=THIS_MODULE;
         dev->cdev.ops=fops;
         err=cdev_add(&dev->cdev,dev_id,1);
         if (err<0)
         {   
             printk(KERN_ALERT "cdev_add not successful for dev_id=%d ",dev_id);
             goto OUT;
         }
    //}
     return 0;
OUT: return -1;   
}
module_init(start_module);
