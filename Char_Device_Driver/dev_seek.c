#include "header.h"
#include "declarations.h"

loff_t dev_seek(struct file *filp,loff_t offset,int origin)
{  
   loff_t new_pos=0;
   printk(KERN_INFO "Inside lseek");
   switch (origin)
   {
    case SEEK_SET:
                 new_pos=offset;
                 break;
    case SEEK_CUR:
                 printk(KERN_INFO "Inside lseek currt file pos=%d\n",(int)filp->f_pos);
                 new_pos=filp->f_pos+offset;
                 break;
    case SEEK_END:
                 new_pos=DEVICESIZE-offset;
                 break;
   }
   if(new_pos>=DEVICESIZE)
       new_pos=DEVICESIZE;

   if(new_pos<0)
      new_pos=0;
   filp->f_pos=new_pos;
   
   printk(KERN_INFO "Inside lseek value of new_pos=%lld",new_pos);
   return new_pos;
}
