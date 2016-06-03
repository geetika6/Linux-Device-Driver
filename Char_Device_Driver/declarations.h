extern dev_t dev_id;
extern int majorno,minorno,nod;

#define DEVNAME "Geetika's Driver"
struct skull_dev {
    struct scull_qset *data;  /* Pointer to first quantum set */
    int quantum;              /* the current quantum size */
    int qset;                 /* the current array size */
    unsigned long size;       /* amount of data stored here */
    struct cdev cdev;     /* Char device structure      */
};
extern struct skull_dev *dev;  
//extern struct file_operations fops 
struct skull_qset {
    void **data;
    struct skull_qset *next;
};
extern struct skull_qset *qset;
int dev_open(struct inode *,struct file *);
int dev_release(struct inode *,struct file *);
