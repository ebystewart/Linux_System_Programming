# Linux_System_Programming
A collection of kernel space programs (kernel objects) on linux

LDD_kthreads : Demonstrates creation and cancellation of kernel threads using kthread_*() APIs

LDD_ModuleParam : Passing arguments to a LKM
usage example: sudo insmod ModuleParam.ko dev_no=8 dev_name="cake"

LDD_Inter-Module_Communication: uses symbol_get()/symbol_put(), inter_module_get()/inter_module_put()/inter_module_register(), inter_module_unregister() APIs to demonstrate communication between two kernel modules.

LDD_LoadModule: Demonstrates loading of another kernel module using request_module() API
usage:
    #1: The module to be loaded should be already available as an installed module in /lib/modules/<kernel_version>/kernel/../
    #2: The list of loaded modules can be found using lsmod command
    #3: The list of installed modules can be found by "cat /lib/modules/<kernel_version>/modules.dep"
