#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<linux/types.h>
#include<linux/kdev_t.h>
dev_t dev=0;

MODULE_LICENSE("GPL");
static int __init char_init(void)
{
    alloc_chrdev_region(&dev,0,1,"abnormal");
    printk(KERN_INFO "Major=%d\n Minor = %d\n",MAJOR(dev),MINOR(dev));
    printk(KERN_INFO "inserted successfully.\n");
    return 0;
}

static void __exit char_exit(void)
{
    unregister_chrdev_region(dev,1);
    printk(KERN_INFO "Module completed.\n");
}

module_init(char_init);
module_exit(char_exit);
