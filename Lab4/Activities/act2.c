#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {

  printf("Before Forking\n");
  
  pid_t pid = fork();
  
  if(pid == 0) {
    printf("Child Process: PID = %d, Parent PID = %d\n" , getpid(), getppid());
  } else {
    printf("Parent Process: PID = %d, Child PID = %d\n", getpid(), pid);
  }
  
  printf("End of Program: PID = %d\n", getpid());

  return 0;
  
}


