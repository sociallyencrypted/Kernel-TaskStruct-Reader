
#include <linux/init.h> 
#include <linux/kernel.h> 
#include <linux/module.h> 
#include <linux/moduleparam.h> 
#include <linux/sched.h>
#include <linux/pid.h>
#include <linux/cred.h>
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mehul Arora (sociallyencrypted)"); 
MODULE_DESCRIPTION("A kernel module to read the task struct of a process."); 
 
int pidint = 0;
module_param(pidint, int, S_IRUSR | S_IWUSR);
MODULE_PARM_DESC(pidint, "The PID of the process whose task struct is to be read.");

static int __init taskStructReader_init(void) 
{
    // find task struct of the process
    struct task_struct *task;
    task = pid_task(find_vpid(pidint), PIDTYPE_PID);
    if (task == NULL) {
        pr_info("No such process exists.\n");
        return 0;
    }
    // print pid, uid, gid, command path
    pr_info("PID: %d\n", task->pid);
    pr_info("UID: %d\n", task->cred->uid.val);
    pr_info("GID: %d\n", task->cred->gid.val);
    pr_info("Command Path: %s\n", task->comm);
    return 0;
} 
 
static void __exit taskStructReader_exit(void) 
{ 
    pr_info("taskStructReader module finished.\n");
} 
 
module_init(taskStructReader_init); 
module_exit(taskStructReader_exit);