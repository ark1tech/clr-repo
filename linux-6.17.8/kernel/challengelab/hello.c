#include <linux/kernel.h>
#include <linux/syscalls.h>

// CLR
SYSCALL_DEFINE0(hello)
{
	printk("Hello from the Linux kernel!\n");
	return 0;
}