#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<linux/types.h>
#include<linux/kdev_t.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("shikha");

dev_t dev=MKDEV(100,50);

static int __init char_init(void)
{
    register_chrdev_region(dev,1,"char device");
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


