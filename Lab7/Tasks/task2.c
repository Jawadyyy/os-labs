#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *take_order(void *arg) {
    printf("Taking Orders | Process ID: %d | Thread ID: %lu\n", getpid(), pthread_self());
    pthread_exit(NULL);
}

void *cook_food(void *arg) {
    printf("Cooking Food  | Process ID: %d | Thread ID: %lu\n", getpid(), pthread_self());
    pthread_exit(NULL);
}

void *deliver_food(void *arg) {
    printf("Delivering Food | Process ID: %d | Thread ID: %lu\n", getpid(), pthread_self());
    pthread_exit(NULL);
}

int main() {
    pthread_t t1, t2, t3;

    printf("Restaurant\n");

    pthread_create(&t1, NULL, take_order, NULL);
    pthread_create(&t2, NULL, cook_food, NULL);
    pthread_create(&t3, NULL, deliver_food, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    printf("System Logging Off\n");
    return 0;
}
