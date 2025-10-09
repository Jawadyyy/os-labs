#include <stdio.h>
#include <unistd.h>

int main() {

  printf("Start: PID = %d\n", getpid());
  
  fork();
  fork();
  
  printf("Process PID = %d, Parent PID = %d\n" , getpid(),getppid());

  return 0;
}
