#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

#include <linux/uaccess.h>	// copy_to_user
#include <linux/proc_fs.h>	// proc_create
#include <linux/seq_file.h>	// struct fops

#define DRIVER_AUTHOR "Christophe Barès"
#define DRIVER_DESC "Hello world Module"
#define DRIVER_LICENSE "GPL"


int hello_init(void)
{
	printk(KERN_INFO "Hello world!\n");
	return 0;
}

void hello_exit(void)
{
	printk(KERN_ALERT "Bye bye...\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE(DRIVER_LICENSE);
MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);

