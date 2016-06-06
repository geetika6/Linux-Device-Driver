#include "header.h"
#include "declarations.h"


ssize_t dev_write(struct file *filp,const char __user *ubuff,size_t size,loff_t *loff)
{  
   int i;
   //int notc,i;
    struct scull_dev *ldev;
    //char desp[size]; 
    printk(KERN_INFO "Inside dev_write");
    ldev=NULL;
    //since private data was of void type
    ldev =(struct scull_dev *)filp->private_data;
    if(!ldev)
    {
         printk(KERN_ERR "dev not found");
         goto OUT;
    }
   //after pointing private data to the ldev, we need to create pointer from source to destination for transer of data
   //for this we created destination in form of qset
   //now the ldev first set will point to this set of qsets
   //for this we need to use copy_from_user
   //
    printk(KERN_INFO "Inside dev_write size of write task from user=  %lu",size);
    for (i=0;i<size;i++)
    {
         printk(KERN_INFO "Inside dev_write data of write task from user=  %d",*(ubuff+i));
    }
    
    //notc=copy_from_user(desp,ubuff,size); 
    //for (i=0;i<size;i++)
    //{
    //     printk(KERN_INFO "Inside dev_write data of write task to desp=  %d",*(desp+i));
    //}
   ldev->data=creat_scull(ldev,size,ubuff);
   if(!ldev->data)
   {
         printk(KERN_ERR "ldev-sqset not allocated memory");
         goto OUT;

   }
  // printk(KERN_INFO "Inside dev_write data from user not copied =  %d",notc);
   printk(KERN_INFO "Leaving dev_write");
   return 0;
OUT:
     return -7;
}
