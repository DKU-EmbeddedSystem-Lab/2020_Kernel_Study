/*
 * <Linux Kernel Internal> by Jongmoo Choi
 * pg 175, 181~186
 *
 *****************************************
 **					**
 ** 	Implement a New system call! 	**
 **					**
 *****************************************
 *
 * <리눅스 커널 내부구조> : pg187 실습문제2번
 * 교재에 소개된 내용을 바탕으로 새로운 시스템 호출을 구현해보자.
 *
 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * !!!	Caution					!!!
 * !!!	  > We need to implement inho_syscall.c	!!!
 * !!!	    under '/kernel' dir			!!!
 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 *	
 * src : /kernel/inho_syscall.c
 * create by inhoinno
 * 15July2020
 * * */

//THIS SHOULD BE PLACED IN '/kernel/~.c'
//<LINUX KERNEL INTERNAL> pg176

#include <linux/unistd.h>
#include <linux/errno.h>
#include <linux/kernel.h>
#include <linux/sched.h>

asmlinkage long inho_syscall(void)
{
	printk("<0> (New Syscall by inhoinno)Hello Linux, I'm in Kernel -Inho- +_+ ")
	
	printk("<0> PID %d \n",current->pid);	
	printk("<0> TGID %d \n",current->tgid);	
	printk("<0> PPID %d \n",current->parent->pid);	
	printk("<0> STATE %d \n",current->state);	
	printk("<0> PRIORITY %d \n",current->prio);	
	printk("<0> POLICY %d \n",current->policy);	
	printk("<0> Number of MAJOR FAULT %d \n",current->maj_flt);	
	printk("<0> Number of MINOR FAULT %d \n",current->min_flt);	
					
		
	return 0;
}

EXPORT_SYMBOL_GPL(sys_newsyscall);
