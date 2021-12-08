#include "headers/syscall_hook.h"
#include "headers/util.h"
#include <kallsyms.h>


#define MAX_SYSCALL_NUMBER 332
#define ENABLE_WP write_cr0(read_cr0() | (0x10000));
#define DISABLE_WP write_cr0(read_cr0() & (~0x10000));

struct hook_list* hooked_syscalls;

syscall_t* find_syscall_table() {
	return (syscall_t*)kallsyms_lookup_name("sys_call_table");
}


int hook_syscall(unsigned short syscall_nr, syscall_t hook_func, syscall_t* syscall_table) {
	// arguments check
	if (syscall_table == NULL || syscall_nr < 0 || syscall_nr > MAX_SYSCALL_NUMBER) {
		return -1;
	}
	// checking the hooked syscalls linked list is initialized
	if (hooked_syscalls == NULL) {
		return -1;
	}
	// allocating a new hooked_syscall struct
	struct hooked_syscall* hooked_syscall = kmalloc(sizeof(struct hooked_syscall), GFP_KERNEL);
	if (hooked_syscall == NULL) {
		printk(KERN_ERR "Allocation error");
		destroy_list(hooked_syscalls);
		return -1;
	}
	hooked_syscall->syscall_nr = syscall_nr;
	hooked_syscall->orig_func = (syscall_t)syscall_table[syscall_nr];
	int res = add_to_list(&hooked_syscalls, hooked_syscall);
	if (res == -1) {
		printk(KERN_ERR "Couldn't add syscall to list");
		destroy_list(hooked_syscalls);
		return -1;
	}

	DISABLE_WP
	syscall_table[syscall_nr] = hook_func;
	ENABLE_WP

	return 1;
}
void restore_syscall(struct hooked_syscall* hooked_syscall) {
	syscall_t* syscall_table = find_syscall_table();
	DISABLE_WP
	syscall_table[hooked_syscall->syscall_nr] = hooked_syscall->orig_func;
	ENABLE WP
}

void restore_all_syscalls() {
	// traversing the hooked syscalls list, restoring each of them and freeing the memory.
	struct hook_list* curr = hooked_syscalls;
	while (hooked_syscalls != NULL) {
		restore_syscall(curr->hooked_syscall);
		kfree(curr->hooked_syscall);
		curr = curr->next;
	}
	destroy_list(hooked_syscalls);
	hooked_syscalls = NULL;
}
