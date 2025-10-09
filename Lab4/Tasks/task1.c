#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {

  pid_t pid = fork();
  
  if(pid == 0) {
    printf("This is a Child Process: PID = %d\n" , getpid());
  } else {
    printf("This is a Parent Process: PID = %d\n", getpid());
  }
  
  return 0;
  
}


