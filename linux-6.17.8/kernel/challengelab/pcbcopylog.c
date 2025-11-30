#include <linux/kernel.h>
#include <linux/syscalls.h>

// CLR
int pcbcopylog_flag;

SYSCALL_DEFINE1(pcbcopylog, int, flag) {
    pcbcopylog_flag = flag;
    return 0;
}1