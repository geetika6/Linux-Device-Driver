extern dev_t dev_id;
extern int majorno,minorno,nod;

#define DEVNAME "Geetika's Driver"
#define DEVICESIZE 1024
#define DATASIZE 0 
#define QUANTUMSIZE 8
#define QSETSIZE 3

struct scull_dev {
	struct scull_sqset *sqset;  /* Pointer to first quantum set */
	int quantumsize;              /* the current device quantum size */
	int qsetsize;                 /* the device array size */
	int devicesize;              /* the global device size */
	int datasize;                 /* the data size */
	unsigned long size;       /* amount of data stored here */
	struct cdev cdev;     /* Char device structure      */
	struct semaphore sem;     /*1 Semaphore for each device      */

};
extern struct scull_dev *dev,*gdev;  
//extern struct file_operations fops 
struct scull_sqset {
	void **data;
	struct scull_sqset *next;
};
extern int quantum ;
extern int qset ;
int dev_open(struct inode *,struct file *);
int dev_release(struct inode *,struct file *);
int trim_dev(struct scull_dev *);
void ** creat_sqset(struct scull_dev *,struct scull_sqset *);
struct scull_sqset * creat_scull(struct scull_dev *,size_t);
struct scull_sqset * traverse_scull(struct scull_dev *,size_t);
ssize_t dev_write(struct file *,const char __user *,size_t ,loff_t *);
ssize_t dev_read(struct file *,char __user *,size_t ,loff_t *);
long dev_ioctl(struct file *, unsigned int, unsigned long);
loff_t dev_seek(struct file *,loff_t,int);

