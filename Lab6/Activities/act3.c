#include <stdio.h>
#include <unistd.h>

int main() {
    int pipefd[2];
    pipe(pipefd);
    int number;

    if(fork() == 0) {
        close(pipefd[1]);
        read(pipefd[0], &number, sizeof(number));

        int fac = 1;

        for(int i = 1; i <= number; i++) {
            fac = fac * i;
        }

        printf("Factorial is: %d\n", fac);

        close(pipefd[0]);
    }

    else {
        close(pipefd[0]);
        printf("Enter A Number to Compute Factorial: ");
        scanf("%d",&number);   
        write(pipefd[1], &number, sizeof(number));
        close(pipefd[1]);
    }

    return 0;
}