/*FILE_OPERATIONS ON HOST MACHINE Using "echo" and "cat" command*/
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/err.h>
#include <linux/cdev.h>
#include <linux/device.h>

dev_t dev = 0;
static struct class *dev_class;
static struct cdev file_cdev;


static int      __init file_oper_init(void);
static void     __exit file_oper_exit(void);
static int      file_open(struct inode *inode, struct file *file);
static int      file_release(struct inode *inode, struct file *file);
static ssize_t  file_read(struct file *filp, char __user *buf, size_t len,loff_t * off);
static ssize_t  file_write(struct file *filp, const char *buf, size_t len, loff_t * off);

static struct file_operations fops =
{
    .owner      = THIS_MODULE,
    .read       = file_read,
    .write      = file_write,
    .open       = file_open,
    .release    = file_release,
};


static int file_open(struct inode *inode, struct file *file)
{
        pr_info("Driver Open Function Called...!!!\n");
        return 0;
}

\
static int file_release(struct inode *inode, struct file *file)
{
        pr_info("Driver Release Function Called...!!!\n");
        return 0;
}



static ssize_t file_read(struct file *filp, char __user *buf, size_t len, loff_t *off)
{
        pr_info("Driver Read Function Called...!!!\n");
        return 0;
}



static ssize_t file_write(struct file *filp, const char __user *buf, size_t len, loff_t *off)
{
        pr_info("Driver Write Function Called...!!!\n");
        return len;
}


static int __init file_oper_init(void)
{
        
        if((alloc_chrdev_region(&dev, 0, 1, "file_Dev")) <0)
        {
                pr_err("Cannot allocate major number\n");
                return -1;
        }
        pr_info("Major = %d Minor = %d \n",MAJOR(dev), MINOR(dev));

        
        cdev_init(&file_cdev,&fops);

        
        if((cdev_add(&file_cdev,dev,1)) < 0)
        {
            pr_err("Cannot add the device to the system\n");
            goto r_class;
        }

        
        if(IS_ERR(dev_class = class_create(THIS_MODULE,"file_class")))
        {
            pr_err("Cannot create the struct class\n");
            goto r_class;
        }

        
        if(IS_ERR(device_create(dev_class,NULL,dev,NULL,"file_device")))
        {
            pr_err("Cannot create the Device 1\n");
            goto r_device;
        }
        pr_info("Device Driver Insert...Done!!!\n");
      return 0;

r_device:
        class_destroy(dev_class);
r_class:
        unregister_chrdev_region(dev,1);
        return -1;
}


static void __exit file_oper_exit(void)
{
        device_destroy(dev_class,dev);
        class_destroy(dev_class);
        cdev_del(&file_cdev);
        unregister_chrdev_region(dev, 1);
        pr_info("Device Driver Remove...Done!!!\n");
}

module_init(file_oper_init);
module_exit(file_oper_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("CDAC");
MODULE_DESCRIPTION("File Operations");


//make
//sudo insmod fileop.ko
//lsmod
//sudo dmesg -c
//sudo -s
//ls -l/dev
//echo 1 > /dev/file_device
//exit
