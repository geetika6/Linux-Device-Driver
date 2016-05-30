#include </root/modules/header.h>
int __init init_module(void)
{
printk(KERN_INFO "Hello world \n");
 return 0;
}
void __exit cleanup_module(void)
{
printk(KERN_INFO "Bye bye world \n");
}
