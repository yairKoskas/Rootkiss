#ifndef __SYSCALL_HOOK_H
#define __SYSCALL_HOOK_H

#include <linux/slab.h>
#include <linux/fs.h>
#include <linux/kallsyms.h>

typedef asmlinkage long (*syscall_t)(const struct pt_regs* regs);

struct hooked_syscall {
	syscall_t orig_func;
	unsigned short syscall_nr;
};

struct hook_list {
	struct hooked_syscall* hooked_syscall;
	struct hook_list* next;
};

syscall_t* find_syscall_table(void);
int hook_syscall(unsigned short syscall_nr, syscall_t hook_func, syscall_t* syscall_table);
void restore_syscall(struct hooked_syscall* hooked_syscall);
void restore_all_syscalls(void);

#endif
