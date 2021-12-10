SRCDIR := src
obj-m += core.o
core-objs := $(SRCDIR)/priv_esc.o $(SRCDIR)/syscall_hook.o $(SRCDIR)/utils.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
