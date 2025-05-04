#include <linux/module.h>
#include <linux/init.h>
#include <linux/kthread.h>
#include <linux/sched.h>
#include <linux/delay.h>

/* Meta Data */
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Eby Stewart");
MODULE_DESCRIPTION("Demo of threads in Kernel Space");

static struct task_struct *kthread_1;
static struct task_struct *kthread_2;
static int t1_data = 1;
static int t2_data = 2;

/* kernel thread handlers */
int thread_handler_1(void *arg)
{
    int tid = *(int *)arg;
    while(kthread_should_stop() == 0U){
        printk("THREAD : Running thread %d\n", tid);
        msleep(5000);
    }
    return 0;
}

int thread_handler_2(void *arg)
{
    int tid = *(int *)arg;
    while(kthread_should_stop() == 0U){
        printk("THREAD : Running thread %d\n", tid);
        msleep(5000);
    }
    return 0;
}


static int __init ModuleInit(void)
{
    printk("INFO : Module Init \n");

    /* Create thread #1 - This creates the thread, but doesn't start it*/
    kthread_1 = kthread_create(thread_handler_1, &t1_data, "Kthread_1");
    if(kthread_1 != NULL)
    {
        /* Start the thread */
        wake_up_process(kthread_1);
        printk("INFO: Thread #1 is started\n");
    }
    else{
        printk("ERROR: Thread #1 could not be created\n");
        return -1;
    }

    /* Create thread #2 - This creates the thread and starts it */
    kthread_2 = kthread_run(thread_handler_2, &t2_data, "kthread_2");
    if(kthread_2 != NULL){
        printk("INFO: Thread 2 started\n");
    }
    else{
        printk("ERROR: Thread 3 couldn't be started\n");
        kthread_stop(kthread_1);
        return -1;
    }

    return 0;
}

static void __exit ModuleExit(void)
{
    printk("INFO: Module Exit\n");
    kthread_stop(kthread_1);
    kthread_stop(kthread_2);
}


module_init(ModuleInit);
module_exit(ModuleExit);