#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *single_thread(void *arg) {
    printf("Welcome to the Company Thread \n");
    printf("Proces Id: %d Thread ID: %lu \n", getpid(), pthread_self());
    printf("System has been Initialized\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t t;
    printf("Main Thread Before Company Thread \n");
    pthread_create(&t, NULL, single_thread, NULL);
    pthread_join(t, NULL);

    return 0;
}