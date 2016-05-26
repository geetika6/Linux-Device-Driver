#include </root/modules/header.h>
int __init init_module(void)
{
printk(KERN_ALERT "Hello world \n");
 return -1;
}
void __exit cleanup_module(void)
{
printk(KERN_ALERT "Bye bye world \n");
}
