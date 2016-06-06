#include "header.h"
#include "declarations.h"

struct scull_sqset *ptr=NULL;
struct scull_sqset *curr = NULL;
struct scull_sqset *head = NULL;

struct scull_sqset * creat_scull(struct scull_dev *fdev,size_t size,const char __user *ubuff)
{  
    //int noi,i,j,k,r=8,c=3,count;
    int noi,i;
    //int arr[4][8];
    //char **arr=(char **)kmalloc(r*sizeof(char *),GFP_KERNEL);
   //count = 0;
   //for (j = 0; j <  c; j++)
   //{
   //  for (k = 0; k < r; k++)
   //  {
   //      arr[j][k] = ++count; 
   //      printk(KERN_INFO "value of arr[j][k]=%d ,k= %d,j=%d", arr[j][k],k,j);
   //  }
   //}     

    //for (j = 0; j <  r; j++)
    //  for (k = 0; k < c; k++)
    //     printk(KERN_INFO"value of arr[k][j]=%c ,k= %d,j=%d", arr[k][j],k,j);
  // arr[0][0]=1;
  // arr[0][1]=1;
  // arr[0]={"1","2","3","4","5","6","7","8"};
  // arr[1]={9,10,11,12,13,14,15,16};
  // arr[2]={17,18,19,20,21,22,23,24};
  // arr[3]={25,26};
     
    printk(KERN_INFO "Inside creat_scull");
    noi=size/(fdev->qsetsize *fdev->quantumsize);
    if (size %(fdev->qsetsize *fdev->quantumsize)>0)
        noi++;
       
    printk(KERN_INFO "no of scull_sqset needed =%d",noi);
    for (i=0;i<noi;i++)
    {
        printk(KERN_INFO "Inside creat_scull for loop");
        if (NULL==curr)
        {
        printk(KERN_INFO "Inside creat_scull for loop if loop ");
             ptr=(struct scull_sqset *)kmalloc(sizeof(struct scull_sqset),GFP_KERNEL);
             if (!ptr)
             {
                  printk(KERN_ERR "\n head Node creation failed \n");
             }
             curr = head = ptr;
             ptr->next = NULL;
             printk(KERN_INFO "address of headnode =%p \n",ptr);
             
        }
        else 
        {
        printk(KERN_INFO "Inside creat_scull for loop else loop ");
             ptr=(struct scull_sqset *)kmalloc(sizeof(struct scull_sqset),GFP_KERNEL);
             if (!ptr)
             {
                  printk(KERN_ERR "\n Node i'th = %d creation failed \n",i);
             }
             printk(KERN_INFO "node i = %d, ptr add = %p ,curr add= %p \n",i,ptr,curr);
             curr->next=ptr ;
             curr=curr->next;
             ptr->next = NULL;
             printk(KERN_INFO "node i = %d, ptr add = %p ,curr add= %p \n",i,ptr,curr);
               
        }
       // lqset=link_scull(noi,*ubuff); 
        printk(KERN_INFO "Inside creat_scull for loop ending ");
    }
    //this lqset points to the first item which is the head node in the linked list
   //notc=copy_from_user(desp,ubuff,size);
   //for (i=0;i<fdev->qsetsize;i++)
   //   {
   //             ptr->data[i]=&arr[i];
   //   }

    return ptr;
}
