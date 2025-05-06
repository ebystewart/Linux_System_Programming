#include <linux/module.h>
#include <linux/init.h>
#include <linux/stat.h>
#include <linux/kmod.h>
#include <linux/capability.h>

/* Ref #1: https://www.oreilly.com/library/view/linux-device-drivers/0596000081/ch11.html */
/* Ref #2: https://duasynt.com/blog/linux-kernel-module-autoloading */
/* ref #3: https://access.redhat.com/solutions/4246821 */

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Eby Stewart");
MODULE_DESCRIPTION("Kernel module demo to load another module");

int __init ModuleInit(void);
void __exit ModuleExit(void);

int __init ModuleInit(void){
    printk("LKM Initialized\n");

    struct module *mod;
    struct mutex module_mutex;
    mutex_lock(&module_mutex);
    //mod = find_module("kthread"); // need to check find_module usage
    //if(!mod)
    {
        mutex_unlock(&module_mutex);
        request_module("cmac"); // This loads cmac from /lib/modules/6.11.0-24-generic/kernel/crypto
    }
    //else
    {
        try_module_get(mod);
        //mutex_unlock(&module_mutex);
    }
    return 0;
}

void __exit ModuleExit(void){
    printk("Unloading kernel module,..... Bye Bye!!\n");
}

module_init(ModuleInit);
module_exit(ModuleExit);
