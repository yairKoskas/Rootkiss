#ifndef __PRIV_ESC_H
#define __PRIV_ESC_H

#include <linux/cred.h>

struct privs {
	int pid;
	struct cred* orig_creds;
	struct task_struct* orig_task;
	struct privs* next;
};

void escalate_by_pid(int pid);
void descalate_by_pid(int pid);
void restore_all_privileges(void);

#endif
