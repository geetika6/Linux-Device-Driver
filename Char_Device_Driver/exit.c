#include "header.h"
#include "declarations.h"
//struct skull_dev *dev;
static void __exit exit_module(void)
{
   printk(KERN_INFO "Bye bye world \n");
   cdev_del(&dev->cdev);
   kfree(dev);
   unregister_chrdev_region(dev_id,nod);
}
module_exit(exit_module);
