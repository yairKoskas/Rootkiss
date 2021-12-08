#ifndef __UTILS_H
#define __UTILS_H

int add_to_list(struct hook_list** head, struct hooked_syscall* new_hooked_syscall);
void destroy_list(struct hook_list* head);

#endif
