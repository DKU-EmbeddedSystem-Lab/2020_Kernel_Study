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
#include <linux/unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "mystat.h"

#define MY_SYSCALL_NO 480 
int main(int argc, char * argv[])
{
	int task_number;
	struct mystat* mybuf;
	if(argc!=2){
		printf("Usage : a.out pid \n");
		exit(1);
	}

	task_number = atoi(argv[1]);
	mybuf = (char *)malloc(sizeof(struct mystat));
	if(mybuf =NULL)
		exit(1);

	syscall(MY_SYSCALL_NO,task_number,mybuf);

	
	printf("pid  		:	%d \n", (int)mybuf->pid);
	printf("ppid 		:	%d \n", (int)mybuf->ppid);
	printf("state 		:	%d \n", (int)mybuf->stat);
	printf("policy 		:	%d \n", (int)mybuf->policy);
	printf("file count	:	%d \n", (int)mybuf->open_files);
	printf("Start time 	:	%d \n", (int)mybuf->starttime);
	
	return 0;
}
