#include <stdio.h>
#include <unistd.h>  
#include <sys/wait.h> 
#include <stdlib.h>

int main() {
    pid_t pid = fork();  

    if (pid == 0) {
        printf("Child process (PID = %d) exiting\n", getpid());
        exit(0);
    } 
    else {
        printf("Parent process (PID = %d) sleeping for 15 seconds\n", getpid());
        sleep(15);
        wait(NULL);
        printf("Parent collected child's exit status. Zombie removed\n");
    }

    return 0;
}
