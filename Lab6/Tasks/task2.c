#include <stdio.h>
#include <pthread.h>

void *sum_function(void *arg) {
    int N = *(int *)arg;
    int sum = N * (N + 1) / 2;
    printf("Sum of first %d natural numbers is: %d\n", N, sum);
    return NULL;
}

void *factorial_function(void *arg) {
    int N = *(int *)arg;
    long long factorial = 1;
    for (int i = 1; i <= N; i++) {
        factorial *= i;
    }
    printf("Factorial of %d is: %lld\n", N, factorial);
    return NULL;
}

int main() {
    pthread_t sum_thread, factorial_thread;
    int N;

    printf("Enter a number N: ");
    scanf("%d", &N);

    pthread_create(&sum_thread, NULL, sum_function, &N);
    pthread_create(&factorial_thread, NULL, factorial_function, &N);

    pthread_join(sum_thread, NULL);
    pthread_join(factorial_thread, NULL);

    return 0;
}
