#ifndef __UTILS_H
#define __UTILS_H

#include "syscall_hook.h"

int add_to_list(struct hook_list** head, struct hooked_syscall* new_hooked_syscall);
int destroy_list(struct hook_list* head);

#endif
