extern dev_t dev_id;
extern int majorno,minorno,nod;

#define DEVNAME "Geetika's Driver"
extern struct skull_dev {
    struct scull_qset *data;  /* Pointer to first quantum set */
    int quantum;              /* the current quantum size */
    int qset;                 /* the current array size */
    unsigned long size;       /* amount of data stored here */
    struct cdev cdev     /* Char device structure      */
}*dev;  
//extern struct file_operations fops 
extern struct scull_qset {
    void **data;
    struct scull_qset *next
}
