#include <stdio.h>

int main(void) {
    
    if (fork() == 0) {
        printf("HC: Hello From Child\n");
    }

    else {
        printf("HP: Hello From Parent\n");

        wait(NULL);

        printf("CT: child has terminated\n");
    }

}