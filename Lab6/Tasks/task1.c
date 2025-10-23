#include <stdio.h>
#include <unistd.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int pipefd1[2], pipefd2[2];
    pipe(pipefd1);
    pipe(pipefd2);

    int num1, num2;

    if (fork() == 0) {
        close(pipefd1[1]);
        close(pipefd2[0]);

        read(pipefd1[0], &num1, sizeof(num1));
        read(pipefd1[0], &num2, sizeof(num2));

        int result = gcd(num1, num2);

        write(pipefd2[1], &result, sizeof(result));

        close(pipefd1[0]);
        close(pipefd2[1]);
    }
    else {
        int result;

        close(pipefd1[0]);
        close(pipefd2[1]);

        printf("Enter two numbers: ");
        scanf("%d %d", &num1, &num2);

        write(pipefd1[1], &num1, sizeof(num1));
        write(pipefd1[1], &num2, sizeof(num2));

        read(pipefd2[0], &result, sizeof(result));

        printf("The GCD of %d and %d is: %d\n", num1, num2, result);
        close(pipefd1[1]);
        close(pipefd2[0]);
    }

    return 0;
}
