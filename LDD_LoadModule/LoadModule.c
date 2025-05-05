#include <linux/module.h>
#include <linux/init.h>
#include <linux/stat.h>
#include <linux/kmod.h>
/* Ref #1:  https://www.oreilly.com/library/view/linux-device-drivers/0596000081/ch11.html */
/* Ref #2: https://duasynt.com/blog/linux-kernel-module-autoloading */

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Eby Stewart");
MODULE_DESCRIPTION("Kernel module demo to load another module");

int __init ModuleInit(void);
void __exit ModuleExit(void);

int __init ModuleInit(void){
    printk("LKM Initialized\n");
    request_module("kthread");
    return 0;
}

void __exit ModuleExit(void){
    printk("Unloading kernel module,..... Bye Bye!!\n");
}

module_init(ModuleInit);
module_exit(ModuleExit);
