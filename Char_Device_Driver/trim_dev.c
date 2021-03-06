#include "header.h"
#include "declarations.h"

int trim_dev(struct scull_dev *fdev)
{   
	int l;
	int i=0,noq=0;
	struct scull_sqset *fqset,*lqset;
	lqset=NULL;
	printk(KERN_INFO "Inside trim_dev");
	fqset=fdev->sqset;
	printk(KERN_INFO "fqset =%p",fqset);
	if (!fqset)
	{
		printk(KERN_ERR "fqset for trimming not valid");
		goto OUT;
	}
	noq=fdev->datasize /fdev->quantumsize;
	if (fdev->datasize % fdev->quantumsize)
		noq++;
	printk(KERN_INFO "no of quantum for trimming =%d",noq);
	for (l=0;l<noq;l++)
	{
		if (i==fdev->qsetsize)
		{
			i=0;
			lqset=fqset;
			fqset=fqset->next;
			kfree(lqset->data);
			printk(KERN_INFO "for next item no of loop = %d, quantum for freeing =%d",i,l);
		}
		kfree(fqset->data[i]);
		printk(KERN_INFO "no of loop = %d, quantum for freeing =%d",i,l);
		i++;
	}
	fdev->sqset=NULL;

	return 0;
OUT: 
	return -1;
}
