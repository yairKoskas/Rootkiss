#include "core.h"

int __init rootkiss_init(void) {
	printk(KERN_INFO "Loaded Rootkiss");
}

void __exit rootkiss_exit(void) {
	printk(KERN_INFO "Unloaded Rootkiss");
}
