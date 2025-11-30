#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kprobes.h>
static int handler_pre(struct kprobe *p, struct pt_regs *regs)
{
	pr_info("do_execve called\n");
	return 0;
}
static struct kprobe kp = {
	.symbol_name = "do_execve",
	.pre_handler = handler_pre, // callback :000
};
static int __init kprobe_init(void)
{
	int ret;
	ret = register_kprobe(&kp);
	if (ret < 0) {
		pr_err("register_kprobe failed, returned %d\n", ret);
		return ret;
	}
	pr_info("kprobe registered at %p\n", kp.addr);
	return 0;
}
static void __exit kprobe_exit(void)
{
	unregister_kprobe(&kp);
	pr_info("kprobe unregistered\n");
}
module_init(kprobe_init);
module_exit(kprobe_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("RK Mañago");
MODULE_DESCRIPTION("kprobe for do_execve");