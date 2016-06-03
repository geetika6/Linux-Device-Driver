#include "header.h"
#include "declarations.h"
//struct skull_dev *dev;
static void __exit exit_module(void)
{
   int i=0;
   printk(KERN_INFO "Bye bye world \n");
   while(i<nod)
   {    
       cdev_del(&dev[i].cdev);
       i=i+1;
   }
   kfree(dev);
   unregister_chrdev_region(dev_id,nod);
}
module_exit(exit_module);
