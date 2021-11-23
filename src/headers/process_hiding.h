#ifndef __PROCESS_HIDING_H
#define __PROCESS_HIDING_H

#include <linux/pid.h>

void hide_process(int pid);
void reveal_process(int pid);

#endif
