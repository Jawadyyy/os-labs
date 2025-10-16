#include <stdio.h>
#include <unistd.h>  

int main(void) {
    int pid;

    printf("Hello World\n");
    printf("Parent process and pid is : %d.\n", getpid());
    printf("Before forking\n");

    pid = fork();  

    printf("After forking\n");

    if (pid == 0) {
        printf("Child process and pid is : %d.\n", getpid());
    }
    else {
        printf("Parent process and pid is : %d.\n", getpid());
    }

    return 0;
}
