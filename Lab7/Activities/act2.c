#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void* thread_func(void* arg) {
    int num = *((int *)arg);
    printf("Thread %d Process Id: %d Thread ID: %lu \n",num,getpid(),pthread_self());
    pthread_exit(NULL);
}

int main() {

    pthread_t threads[3];
    int thread_num[3];

    for(int i=0; i<3; i++) {
        thread_num[i] = i+1;
        pthread_create(&threads[i],NULL,thread_func,&thread_num[i]);
    }

    for(int i=0; i<3; i++) {
        pthread_join(threads[i],NULL);
    }

    printf("Process ID: %d Thread ID: %lu \n",getpid(),pthread_self());


    return 0;
}