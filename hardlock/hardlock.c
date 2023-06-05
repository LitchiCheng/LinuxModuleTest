#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kthread.h>
#include <linux/spinlock.h>

MODULE_LICENSE("GPL");
static int hog_thread(void *data)
{
    static DEFINE_SPINLOCK(lock);
    unsigned long flags;
    printk(KERN_INFO "Hogging a CPU now\n");
    spin_lock_irqsave(&lock, flags);
    while (1);/* unreached */
    return 0;
}

static int __init hog_init(void)
{
    kthread_run(&hog_thread, NULL, "hog");
    return 0;
}

module_init(hog_init);