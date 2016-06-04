extern dev_t dev_id;
extern int majorno,minorno,nod;

#define DEVNAME "Geetika's Driver"
struct scull_dev {
    struct scull_qset *data;  /* Pointer to first quantum set */
    int quantum;              /* the current quantum size */
    int qset;                 /* the current array size */
    unsigned long size;       /* amount of data stored here */
    struct cdev cdev;     /* Char device structure      */
};
extern struct scull_dev *dev;  
//extern struct file_operations fops 
struct scull_qset {
    void **data;
    struct scull_qset *next;
};
extern struct scull_qset *qset;
int dev_open(struct inode *,struct file *);
int dev_release(struct inode *,struct file *);
int trim_dev(struct scull_dev *);
ssize_t dev_write(struct file *,const char __user *,size_t ,loff_t *);
