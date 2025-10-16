#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    
    printf("Hello! I am the original process with PID: %d\n\n", getpid());

    
    pid_t pid = fork();

    if (pid > 0) {
        printf("Parent: I created a child process with PID: %d\n\n", pid);

    } else if (pid == 0) {
        printf("Child: My PID is %d\n\n", getpid());
    } else {
        perror("fork failed");
        return 1;
    }

    return 0;
}