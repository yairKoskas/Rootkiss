#ifndef __PRIV_ESC_H
#define __PRIV_ESC_H

#include <linux/cred.h>

struct privs {
	int pid;
	struct cred* orig;
	struct task_struct* orig;
	struct privs* next;
}

void escalate_by_pid(int pid);
void descalate_by_pid(int pid);
void restore_all_privileges();

#endif
