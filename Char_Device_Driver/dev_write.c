#include "header.h"
#include "declarations.h"


ssize_t dev_write(struct file *filp,const char __user *ubuff,size_t size,loff_t *loff)
{  
   int i=0;
   int notc,noctw,nocsw;
   //void **arr;
    struct scull_dev *ldev,*fdev;
    struct scull_sqset *fqset,*lqset;
    int qset,quantum;
    //struct scull_sqset *sqset;
     nocsw=0;
     noctw=size;
    //char desp[size]; 
    printk(KERN_INFO "Inside dev_write");
    ldev=fdev=NULL;
    //since private data was of void type
    ldev =(struct scull_dev *)filp->private_data;
    if(!ldev)
    {
         printk(KERN_ERR "dev not found");
         goto OUT;
    }
    ldev->datasize=size; 
   //after pointing private data to the ldev, we need to create pointer from source to destination for transer of data
   //for this we created destination in form of qset
   //now the ldev first set will point to this set of qsets
   //for this we need to use copy_from_user
   //
   qset=ldev->qsetsize;
   quantum=ldev->quantumsize;
   ldev->sqset=creat_scull(ldev,size);
   
   fdev=ldev;
   lqset=ldev->sqset;
   fqset=ldev->sqset;
           printk(KERN_INFO "inside dev_write lqset add  recieved = %p \n",lqset);
   lqset=lqset->next;
           printk(KERN_INFO "inside dev_write lqset data add next recieved = %p \n",lqset);
   lqset=lqset->next;
           printk(KERN_INFO "inside dev_write fqset add next next recieved = %p \n",lqset);
   if(!ldev->sqset)
   {
         printk(KERN_ERR "ldev-sqset not allocated memory");
         goto OUT;

   }
   printk(KERN_INFO "copying data in dev_write");
   while (noctw)
   {
        if (noctw>quantum)
        noctw=quantum ;
        notc=copy_from_user(fqset->data[i],ubuff+nocsw,noctw);
        if (notc)
        {  
            printk(KERN_INFO "in dev_write partial write");
        }
        nocsw=nocsw + (noctw-notc) ;
        noctw=size - nocsw ;
        //if (nocsw== ldev->qsetsize *ldev->quantumsize)
        i++;
        if (i==(ldev->qsetsize))
        {
           fqset=fqset->next;
           i=0;
        }
   } 
  

   return 0;
OUT:
     return -7;
}
