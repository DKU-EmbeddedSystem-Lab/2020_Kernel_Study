#include <stdio.h>
#include <stdlib.h>
int main (){


	//I'll make dangle-pointer and use valgrind 
	//gcc -g -o memleak memory_leak.c
	//
	int *origin_p = NULL;
	int * pointing_p= NULL;
	pointing_p = origin_p;

	printf("%p %p\n", origin_p , pointing_p);
       	
}
