#include <linux/module.h>
#include <linux/init.h>
#include <linux/stat.h>
/* Ref: https://litux.nl/mirror/kerneldevelopment/0672327201/ch16lev1sec6.html */

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Eby Stewart");
MODULE_DESCRIPTION("Kernel module demo taking parameters");

/* Declare the parameters */
static unsigned int dev_no = 15U;
static char *dev_name = "Threader";

module_param(dev_no, uint, S_IRUGO); // S_IRUGO means everybody can read
module_param(dev_name, charp, S_IRUGO);

MODULE_PARM_DESC(dev_no, "Device Number");
MODULE_PARM_DESC(dev_name, "Device Name");

int __init ModuleInit(void);
void __exit ModuleExit(void);

int __init ModuleInit(void){
    printk("LKM Initialized\n");
    printk("The device number is %d\n", dev_no);
    printk("The device name is %s\n", dev_name);
    return 0;
}

void __exit ModuleExit(void){
    printk("Unloading kernel module,..... Bye Bye!!\n");
}

module_init(ModuleInit);
module_exit(ModuleExit);
