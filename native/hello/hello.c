#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>


static int hello_init(void)
{
    printk(KERN_ALERT "Hello Shikha\n");
    return 0;
}

static void hello_exit(void)
{
    printk(KERN_ALERT "GOOD BYE\n");
}

module_init(hello_init);
module_exit(hello_exit);
MODULE_AUTHOR("SHIKHA");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("hello shikha");