#include "headers/core.h"
#include "headers/priv_esc.h"

int __init rootkiss_init(void) {
	printk(KERN_INFO "Loaded Rootkiss");
}

void __exit rootkiss_exit(void) {
	printk(KERN_INFO "Unloaded Rootkiss");
}
