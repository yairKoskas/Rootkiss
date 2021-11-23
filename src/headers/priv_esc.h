#ifndef __PRIV_ESC_H
#define __PRIV_ESC_H

#include <linux/cred.h>
#include <linux/pid.h>

void escalate_by_pid(int pid);

#endif
