#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>
#include"kern_add.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("i am");

static int one=1;
static int two=2;

static int __init add_init(void)
{
    printk(KERN_ALERT "\n inside average\n");
    printk(KERN_ALERT "\navg result is :%d\n",my_add(one,two)/2);
    return 0;
}

static void __exit add_exit(void)
{                
    printk(KERN_ALERT "\n leaving average \n");
}

module_init(add_init);
module_exit(add_exit);