#include "header.h"
#include "declarations.h"


struct scull_sqset * traverse_scull(struct scull_dev *fdev,size_t size)
{  
	int noi,i;
	struct scull_sqset *ptr = fdev->sqset;
	struct scull_sqset *head=NULL;
	//char desp[size_sqset];
	printk(KERN_INFO "Inside traverse_scull");
	noi=size/(fdev->qsetsize *fdev->quantumsize);
	if (size %(fdev->qsetsize *fdev->quantumsize)>0)
		noi++;

	printk(KERN_INFO "no of scull_sqset needed =%d",noi);
	//If head node not existing, allocate head
	if (ptr==NULL)
	{
		ptr=fdev->sqset=(struct scull_sqset *)kmalloc(sizeof(struct scull_sqset),GFP_KERNEL);
		if (!ptr)
		{
			printk(KERN_ERR "\n head Node creation failed \n");
		}
		memset(ptr,'\0',sizeof(struct scull_sqset));
		ptr->data=creat_sqset(fdev,ptr);
		head=ptr;
	}
	else
	{
        	printk(KERN_INFO "inside traverse ptr= %p \n",ptr);
		head=ptr;
                
	}
	//If scull already existing, traverse it
	for (i=1;i<noi;i++)
	{
		printk(KERN_INFO "Inside traverse_scull for loop");
		if (NULL==ptr->next)
		{
			printk(KERN_INFO "Inside traverse_scull if loop");
			ptr->next=(struct scull_sqset *)kmalloc(sizeof(struct scull_sqset),GFP_KERNEL);
			if (ptr->next==NULL)
			{
				printk(KERN_ERR "\n Node i'th = %d creation failed \n",i);
			}
			memset(ptr->next,'\0',sizeof(struct scull_sqset));
			ptr->next->data=creat_sqset(fdev,ptr->next);
		}
		ptr=ptr->next;
		continue;
	}

	return head;
}
