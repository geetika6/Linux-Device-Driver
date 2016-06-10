#include "header.h"
#include "declarations.h"


struct scull_sqset * creat_scull(struct scull_dev *fdev,size_t size)
{  
   int noi,i;
    struct scull_sqset *head =NULL;
    struct scull_sqset *curr = NULL;
    struct scull_sqset *ptr = NULL;
   //char desp[size_sqset];
    printk(KERN_INFO "Inside creat_scull");
    noi=size/(fdev->qsetsize *fdev->quantumsize);
    if (size %(fdev->qsetsize *fdev->quantumsize)>0)
        noi++;
       
    printk(KERN_INFO "no of scull_sqset needed =%d",noi);
    for (i=0;i<noi;i++)
    {
        printk(KERN_INFO "Inside creat_scull for loop");
        //if (NULL==curr)
        if (i==0)
        {
             printk(KERN_INFO "Inside creat_scull for loop if loop ");
             ptr=(struct scull_sqset *)kmalloc(sizeof(struct scull_sqset),GFP_KERNEL);
             if (!ptr)
             {
                  printk(KERN_ERR "\n head Node creation failed \n");
             }
             curr = head = ptr;
             ptr->next = NULL;
             memset(ptr,'\0',sizeof(struct scull_sqset));
             head->data=creat_sqset(fdev,head);
        }
        else 
        {
        printk(KERN_INFO "Inside creat_scull for loop else loop ");
             ptr=(struct scull_sqset *)kmalloc(sizeof(struct scull_sqset),GFP_KERNEL);
             if (!ptr)
             {
                  printk(KERN_ERR "\n Node i'th = %d creation failed \n",i);
             }
             curr->next=ptr ;
             curr=curr->next;
             ptr->next = NULL;
             ptr->data=creat_sqset(fdev,ptr);
               
        }
        printk(KERN_INFO "Inside creat_scull for loop ending ");
    }
    
    return head;
}
