#include <stdio.h>
#include <unistd.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
int main()
{
	char buffer[100];
	long length = syscall(549, buffer);
	printf("Process name is: %s\n", buffer);
	printf("Name is %ld characters long\n", length);
}