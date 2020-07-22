/* <Linux Kernel Internal> by Jongmoo Choi
 * pg 175, 181~186
 *
 * src : sys_task.c
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
 * !!!	  > We need to implement newsyscall.c 	!!!
 * !!!	    under kernel/ dir 			!!!
 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 *	
 * src : inho_sys_task.c
 * create by inhoinno
 * 15July2020
 * * 
 * 
 * */
#define _GNU_SOURCE
#include <linux/unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <stdlib.h>


#define MY_SYSCALL_NO 439 
int main()
{
	int err =0;
	syscall(MY_SYSCALL_NO,err);
	
	printf("Process End ...");
	
	return 0;
}
