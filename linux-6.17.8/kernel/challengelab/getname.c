#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/sched.h>

// CLR
SYSCALL_DEFINE1(getname, char *, buffer)
{
	printk("getname: %s\n", get_current()->comm);
	strcpy(buffer, get_current()->comm);
	return strlen(buffer);
}