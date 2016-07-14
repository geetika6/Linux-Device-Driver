#include "header.h"
#include "declarations.h"


ssize_t dev_write(struct file *filp,const char __user *ubuff,size_t size,loff_t *loff)
{  
	int i=0;
	int notc,noctw,nocsw,oiq;
	//void **arr;
	struct scull_dev *ldev,*fdev;
	struct scull_sqset *lqset;
	int qset,quantum;
	//struct scull_sqset *sqset;
	nocsw=oiq=0;
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
	//after pointing private data to the ldev, we need to create pointer from source to destination for transer of data
	//for this we created destination in form of qset
	//now the ldev first set will point to this set of qsets
	//for this we need to use copy_from_user
	//

	qset=ldev->qsetsize;
	quantum=ldev->quantumsize;
	lqset=ldev->sqset;
	printk(KERN_INFO "inside 1 dev_write gdev =%p and lqset= %p \n",gdev->sqset,ldev->sqset);
	i=(int)*loff/quantum;
	oiq=(int)*loff % quantum;
	if (down_interruptible(&ldev->sem))
		return -ERESTARTSYS;
	//TODO traverse scull and make scull , if scull already created, then just data modifying, but how to decide size of scull
	lqset=traverse_scull(ldev,size);

	printk(KERN_INFO "inside dev_write lqset add  recieved = %p \n",lqset);
	if(!lqset)
	{
		printk(KERN_ERR "ldev-sqset not allocated memory");
		goto OUT;

	}
	printk(KERN_INFO "copying data in dev_write");
	while (noctw)
	{
		printk(KERN_INFO "Inside dev_write value of nocsw= %d,i= %d,oiq= %d ,noctw= %d",nocsw,i,oiq,noctw);
		if (i==(ldev->qsetsize))
		{
			lqset=lqset->next;
			i=0;
		}
		if (noctw>quantum)
			noctw = quantum-oiq;
		//	else
		//		noctw=noctw-oiq;
		notc=copy_from_user(lqset->data[i]+oiq,ubuff+nocsw,noctw);
		if (notc)
		{  
			printk(KERN_INFO "in dev_write partial write");
		}
		nocsw=nocsw + (noctw-notc) ;
		noctw=size - nocsw ;
		//if (nocsw== ldev->qsetsize *ldev->quantumsize)
		i++;
		oiq=0;
	} 


	(*loff)+= nocsw;

	/* update the size */
	if (ldev->datasize < (int)*loff)
		ldev->datasize=(int)*loff;
        up(&ldev->sem);
	return nocsw;

OUT:
        up(&ldev->sem);
	return -1;
}
