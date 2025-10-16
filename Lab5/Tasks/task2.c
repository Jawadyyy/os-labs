#include <stdio.h>
#include <unistd.h>  
#include <sys/wait.h> 

int main() {
    int age;

    pid_t pid = fork(); 

    if (pid == 0) {
        printf("From Child Enter your age: ");
        scanf("%d", &age);
    }
    else {
        wait(NULL); 
        printf("From Parent Child has finished executing \n");
        printf("You entered age = %d\n", age);
        printf("From Parent (Parent cannot access childs variable) \n");
    }

    return 0;
}
