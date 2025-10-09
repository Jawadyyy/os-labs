#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {

  pid_t child = fork();
  
  if(child == 0) {
    printf("This is a Child Process: PID = %d\n", getpid());
      pid_t grand_child = fork();
        if(grand_child == 0) {
          printf("This is a GrandChild Process: PID = %d\n", getpid());
        }
        else {
          printf("This is a Child Process: PID = %d\n", getpid());
        }
  } else {
    printf("This is a Parent Process: PID = %d\n", getpid());
  }
  
  return 0;
  
}

