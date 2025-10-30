#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *single_thread(void *arg) {
    printf("Inside Thread Function \n");
    printf("Proces Id: %d Thread ID: %lu \n", getpid(), pthread_self());
    pthread_exit(NULL);
}

int main() {
    pthread_t t;
    printf("Main Thread Before Creating New Thread \n");
    pthread_create(&t, NULL, single_thread, NULL);
    pthread_join(t, NULL);
}