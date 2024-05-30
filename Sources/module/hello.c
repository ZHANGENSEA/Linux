#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

#include <linux/uaccess.h>	// copy_to_user
#include <linux/proc_fs.h>	// proc_create
#include <linux/seq_file.h>	// struct fops

#define DRIVER_AUTHOR "Christophe Barès"
#define DRIVER_DESC "Hello world Module"
#define DRIVER_LICENSE "GPL"

#define TAILLE 256
char message[TAILLE];

static int param = 3;
struct file_operations proc_fops;
struct proc_dir_entry * dir_ensea;


module_param(param, int, 0);
MODULE_PARM_DESC(param, "Un paramètre de ce module");

// fops_read
ssize_t fops_read(struct file *file, char __user *buffer, size_t count, loff_t *ppos){
	int errno=0;
	int copy;

	if (count > TAILLE) count=TAILLE;
	if ((copy=copy_to_user(buffer,message,count)))
	{
		errno = -EFAULT;
	}
	printk(KERN_INFO "message read, %d, %p\n",copy, buffer);
	return count-copy;
}

// fops_write
ssize_t fops_write(struct file *file, const char __user *buffer, size_t count, loff_t *ppos){
	int len = count;

	if (count > TAILLE) len = TAILLE;

	printk(KERN_INFO "Recieving new messag\n"); 
	if ((copy_from_user(message,buffer,count))){
		return -EFAULT;
	}
	message[count] = '\0'; // écrit le caractere NULL à la fin de la chaine
	printk(KERN_INFO "NEW message : %s\n",message);
	return count;
}

int hello_init(void)
{
	printk(KERN_INFO "Hello world!\n");
	printk(KERN_DEBUG "le paramètre est = %d \n", param);
	proc_fops.read = fops_read;		// structure : on utilise "."
	proc_fops.write = fops_write;	// pointeur sur une structure : on utilise "->"
	dir_ensea = proc_mkdir("ensea", NULL);	// Dossier créé dans /proc
	proc_create("test", 0666, dir_ensea, &proc_fops);// Fichier créé dans /proc/ensea

	return 0;
}

void hello_exit(void)
{
	remove_proc_entry("test", dir_ensea);
	remove_proc_entry("ensea", NULL);
	printk(KERN_ALERT "Bye bye...\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE(DRIVER_LICENSE);
MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);

