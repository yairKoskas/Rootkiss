#include "headers/utils.h"


int destroy_list(struct hook_list* head) {
	struct hook_list* tmp;

	while (head != NULL) {
		tmp = head;
		head = head->next;
		kfree(tmp);
	}
	return 1;
}

int add_to_list(struct hook_list** head, struct hooked_syscall* new_hooked_syscall) {
	if (head == NULL) {
		return -1;
	}
	struct hook_list* curr = *head;
	struct hook_list* new_node = (struct hook_list*)kmalloc(sizeof(struct hook_list), GFP_KERNEL);
	if (new_node == NULL) {
		return -1;
	}
	new_node->hooked_syscall = new_hooked_syscall;
	while (curr->next != NULL) {
		curr = curr->next;
	}
	curr->next = new_node;
	return 1;
}
