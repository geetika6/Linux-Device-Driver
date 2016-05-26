static void __exit cleanup_module(void)
{
printk(KERN_ALERT "Bye bye world \n");
}
module_exit(cleanup_module);
