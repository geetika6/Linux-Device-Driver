#include </root/modules/header.h>
#include </root/modules/declarations.h>
struct skull_dev *dev;
static void __exit exit_module(void)
{
   printk(KERN_INFO "Bye bye world \n");
   kfree(dev);
   unregister_chrdev_region(dev_id,nod);
}
module_exit(exit_module);
