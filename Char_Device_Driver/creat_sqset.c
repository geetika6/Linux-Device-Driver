#include "header.h"
#include "declarations.h"
void ** creat_sqset(struct scull_dev *fdev,struct scull_sqset *fqset)
{
    int qset=fdev->qsetsize, quantum=fdev->quantumsize,l;
    void **arr;
//create qset pointer array and give it memory 
    arr  = (void **)kmalloc(sizeof(void *) * qset,GFP_KERNEL);
    if (!arr)
    {
         printk(KERN_ERR "\n sqset set creation failed \n");
    }
//create memory for quantum
    for (l=0;l<qset;l++)
    {
         *(arr+l) = kmalloc(quantum,GFP_KERNEL);
         // printk(KERN_INFO "create_sqset ptr add for lth qset= %d and add= *(data+l) = %p \n",l,*(arr+l));
          memset(*(arr+l), '\0', quantum);
    }
  return arr;
}
