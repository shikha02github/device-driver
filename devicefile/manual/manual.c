/*Manually Creating Device File*/
#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/kdev_t.h>
#include<linux/fs.h>
 
dev_t dev = 0;


static int __init char2_init(void)
{
        
        alloc_chrdev_region(&dev, 0, 1, "CharacterDevice2");
        printk(KERN_INFO "Major = %d Minor = %d \n",MAJOR(dev), MINOR(dev));
        printk(KERN_INFO "Kernel Module Inserted Successfully....\n");
        return 0;
}


static void __exit char2_exit(void)
{
        unregister_chrdev_region(dev, 1);
        printk(KERN_INFO "Kernel Module Removed Successfully...\n");
}
 
module_init(char2_init);
module_exit(char2_exit);
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("CDAC");
MODULE_DESCRIPTION("Manually Creating Device File using mknod");


//make
//sudo insmod static.ko
//dmesg
//sudo mknod -m 777/dev/characterdevice2 c 500 0
//ls -l/dev

