#include <stdio.h>
#include <unistd.h>

int main() {
    int pipefd[2];

    char msg[] = "Hello World";

    char buffer[50];

    pipe(pipefd);

    if(fork() == 0) {
        close(pipefd[1]);
        read(pipefd[0],buffer,sizeof(buffer));
        printf("Child Recieved %s\n", buffer);
        close(pipefd[0]);
    }

    else {
        close(pipefd[0]);
        write(pipefd[1],msg,sizeof(msg));
        close(pipefd[1]);
    }

    return 0;
}