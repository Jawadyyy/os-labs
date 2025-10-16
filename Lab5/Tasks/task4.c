#include <stdio.h>
#include <unistd.h>  
#include <sys/wait.h> 
#include <stdlib.h>

int main() {
    pid_t pid = fork(); 
    if (pid > 0) {
      
        printf("Parent PID: %d\n", getpid());
        printf("Child PID: %d\n", pid);
        sleep(30); 
        printf("Parent exiting...\n");
    } else if (pid == 0) {
        
        printf("Child process exiting...\n");
        exit(0);
    } else {
        perror("fork failed");
    }
    return 0;
}