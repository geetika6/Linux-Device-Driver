#include "header.h"
#include "declarations.h"
void ** creat_sqset(struct scull_dev *fdev,struct scull_sqset *fqset)
{
	int qset=fdev->qsetsize, quantum=fdev->quantumsize,l;
	void **arr=fqset->data;
	if (arr==NULL)
	{
		printk(KERN_INFO "\n qset double pointer not already created,so allocate new \n");
		//create qset pointer array and give it memory 
		arr  = (void **)kmalloc(sizeof(void *) * qset,GFP_KERNEL);
		if (arr==NULL)
		{
			printk(KERN_ERR "\n sqset set creation failed \n");
		}
		memset(arr, '\0', qset*sizeof(void *));
		//create memory for quantum if not already created
		for (l=0;l<qset;l++)
		{
			*(arr+l) = kmalloc(quantum,GFP_KERNEL);
			// printk(KERN_INFO "create_sqset ptr add for lth qset= %d and add= *(data+l) = %p \n",l,*(arr+l));
			memset(*(arr+l), '\0', quantum);
		}
	}
	return arr;
}
