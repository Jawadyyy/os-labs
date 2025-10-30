#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAXN 10

int n;
int A[MAXN][MAXN], B[MAXN][MAXN];
int C_add[MAXN][MAXN], C_sub[MAXN][MAXN], C_mul[MAXN][MAXN];

void *row_add(void *arg) {
    int row = *(int *)arg;
    printf("Add Thread - Row %d | PID: %d | TID: %lu\n", row, getpid(), (unsigned long)pthread_self());
    for (int j = 0; j < n; ++j) {
        C_add[row][j] = A[row][j] + B[row][j];
    }
    pthread_exit(NULL);
}

void *row_sub(void *arg) {
    int row = *(int *)arg;
    printf("Sub Thread - Row %d | PID: %d | TID: %lu\n", row, getpid(), (unsigned long)pthread_self());
    for (int j = 0; j < n; ++j) {
        C_sub[row][j] = A[row][j] - B[row][j];
    }
    pthread_exit(NULL);
}

void *row_mul(void *arg) {
    int row = *(int *)arg;
    printf("Mul Thread - Row %d | PID: %d | TID: %lu\n", row, getpid(), (unsigned long)pthread_self());
    for (int j = 0; j < n; ++j) {
        int sum = 0;
        for (int k = 0; k < n; ++k) {
            sum += A[row][k] * B[k][j];
        }
        C_mul[row][j] = sum;
    }
    pthread_exit(NULL);
}

void print_matrix(const char *title, int M[MAXN][MAXN]) {
    printf("%s\n", title);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) printf("%d ", M[i][j]);
        printf("\n");
    }
}

int main() {
    pthread_t t_add[MAXN], t_sub[MAXN], t_mul[MAXN];
    int idx[MAXN];

    printf("Enter n (matrix size, max %d): ", MAXN);
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAXN) {
        fprintf(stderr, "Invalid n\n");
        return 1;
    }

    printf("Enter matrix A (%d x %d):\n", n, n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%d", &A[i][j]);

    printf("Enter matrix B (%d x %d):\n", n, n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%d", &B[i][j]);

    printf("Main Thread: starting add, sub, mul threads\n");

    for (int i = 0; i < n; ++i) {
        idx[i] = i;
        if (pthread_create(&t_add[i], NULL, row_add, &idx[i]) != 0) {
            perror("pthread_create add");
            return 1;
        }
        if (pthread_create(&t_sub[i], NULL, row_sub, &idx[i]) != 0) {
            perror("pthread_create sub");
            return 1;
        }
        if (pthread_create(&t_mul[i], NULL, row_mul, &idx[i]) != 0) {
            perror("pthread_create mul");
            return 1;
        }
    }

    for (int i = 0; i < n; ++i) {
        pthread_join(t_add[i], NULL);
        pthread_join(t_sub[i], NULL);
        pthread_join(t_mul[i], NULL);
    }

    print_matrix("A + B =", C_add);
    print_matrix("A - B =", C_sub);
    print_matrix("A * B =", C_mul);

    return 0;
}
