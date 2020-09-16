#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "../include/common_threads.h"

sem_t s; 

void *child(void *arg) {
    printf("child\n");
    sleep(1);
    Sem_post(&s);	//Use Semaphore here
    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t p;
    printf("parent: begin\n");
    // init semaphore here
    Sem_init(&s,0);
    Pthread_create(&p, NULL, child, NULL);
    // join(&p) == wait(); ==Sem_wait(s);
    Sem_wait(&s); 	//Use Semaphore here
    printf("parent: end\n");
    return 0;
}

