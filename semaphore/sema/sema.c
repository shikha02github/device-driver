//semaphore program
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/err.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/semaphore.h>

dev_t dev;
//static struct class *dev_class;
static struct cdev driver2_cdev;
struct semaphore my_sema;
int op_result=5;


//static int      __init file_oper_init(void);
//static void     __exit file_oper_exit(void);
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
        printk("Driver Read Functionlaty called...!!!\n");
        unsigned long result;
        ssize_t retval;
        printk("application and functionality");
        printk("before sending the result into the signal");
        result=copy_to_user((char*)buf,(char*)&op_result,sizeof(op_result));
        if(result>=0)
        {
            printk("data successfully created\n");
            retval=sizeof(op_result);
            up(&my_sema);
        }
        else
        {
            printk("error in data reading\n");
            return -1;
        }
        return retval;
}



