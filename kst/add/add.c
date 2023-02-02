#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("i am");

int my_add(int a,int b)
{
    return(a+b);
}
EXPORT_SYMBOL_GPL(my_add);

static int __init hello_init(void)
{
    printk(KERN_ALERT "\ninside add_module\n\n");
    return 0;
}

static void __exit hello_exit(void)
{
    printk(KERN_ALERT "\nleaving add_module\n\n");
}

module_init(hello_init);
module_exit(hello_exit);


//sudo make install
//sudo modprobe -i AVG
//sudo dmesg -c
//sudo lsmod |grep AVG
