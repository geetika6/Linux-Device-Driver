#include "header.h"
#include "declarations.h"


ssize_t dev_read(struct file *filp,char __user *ubuff,size_t size,loff_t *loff)
{  
	int i=0;
	int notc,noctr,nocsr,oiq;
	size_t lsize;
	//void **arr;
	struct scull_dev *ldev;
	struct scull_sqset *lqset;
	int qset,quantum;
	//struct scull_sqset *sqset;
	nocsr=oiq=0;
	//char desp[size]; 
	printk(KERN_INFO "Inside dev_read");
	ldev=NULL;
	//since private data was of void type
	ldev =(struct scull_dev *)filp->private_data;
	if(!ldev)
	{
		printk(KERN_ERR "dev not found");
		goto OUT;
	}
        if (down_interruptible(&ldev->sem))
		return -ERESTARTSYS;
	if (size > ldev->datasize)
	{

		lsize=ldev->datasize; 
		noctr=lsize=lsize-(int)*loff;
	}
	else
	{
		lsize=size;
		//noctr=lsize-(int)*loff;  
		noctr=lsize;  

	}
	qset=ldev->qsetsize;
	quantum=ldev->quantumsize;
	lqset=ldev->sqset;
	if (lqset==NULL)
	{
		printk(KERN_INFO "Read call not possible since scull is not there");
		goto OUT;
	}
	printk(KERN_INFO "Inside dev_read value of noctr= %d",noctr);
	if (noctr>=ldev->devicesize ||lsize==0)
	{
		printk(KERN_INFO "Read call not possible");
		goto OUT;
	}
	//after pointing private data to the ldev, we need to create pointer from source to destination for transer of data
	//for this we need to use copy_to_user
	i=(int)*loff/quantum;
	oiq=(int)*loff % quantum;
	while (noctr)
	{
		if (i==(ldev->qsetsize))
		{
			lqset=lqset->next;
			i=0;
		}
		if (noctr>=quantum)
		{
			noctr=quantum ;
			noctr = quantum-oiq;
		}

		printk(KERN_INFO "Inside dev_read again value of nocsr= %d,i= %d,oiq= %d ,noctr= %d",nocsr,i,oiq,noctr);
		notc=copy_to_user(ubuff+nocsr,lqset->data[i]+oiq,noctr);
		// printk(KERN_INFO "inside dev_read ,data =%s and ptr add  recieved = %p \n",(char*)*(ldev->sqset->data+i),*(ldev->sqset->data+i));
		if (notc)
		{  
			printk(KERN_INFO "in dev_read partial read");
		}
		nocsr=nocsr + (noctr-notc) ;
		noctr=lsize - nocsr ;
		i++;
		oiq=0;
	} 

        up(&ldev->sem);
	return nocsr;
OUT:
        up(&ldev->sem);
	return -1;
}
