/*
 **************************************************
 ***						***
 *** lsproc.c 					***
 *** : Function that prints all tasks of Kernel	***
 ***						***
 **************************************************
 *
 * from https://www.slideshare.net/hoyoung2jung/ss-25561771
 * created by inhoinno
 * 16July2020
 *
 * */

#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/syscalls.h>

asmlinkage int sys_lsproc(void)
{
	int n= 0;
	struct task_struct *p;
	pr_info("
			")
}
