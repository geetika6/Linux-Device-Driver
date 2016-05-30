#include </root/modules/header.h>
#include </root/modules/declarations.h>

dev_t dev_id;
int majorno,minorno;
int ret;
int nod=1;
struct skull_dev *dev;
struct file_operations fops={};
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
    dev=kmalloc(sizeof(struct skull_dev),GFP_KERNEL);
    if (dev==NULL)
    {   
	printk(KERN_ALERT "kmalloc not successful");
        goto OUT;
    }
    memset(dev, 0, sizeof(struct skull_dev));


     return 0;
OUT: return -1;   
}
module_init(start_module);
