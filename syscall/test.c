// test.c

#include "types.h"
#include "stat.h"
#include "user.h"

int main() {
  int pid1, pid2, status1, status2;

  // Fork the first child
  pid1 = fork();
  if (pid1 < 0) {
    printf(1, "Fork failed\n");
    exit(-1);
  }

  if (pid1 == 0) {
    // Child process 1
    printf(1, "Child 1 is running\n");
    exit(10);
  } else {
    // Parent process
    // Fork the second child
    pid2 = fork();
    if (pid2 < 0) {
      printf(1, "Fork failed\n");
      exit(-1);
    }

    if (pid2 == 0) {
      // Child process 2
      printf(1, "Child 2 is running\n");
      exit(20);
    } else {
      // Parent process
      // Wait for the first child and get its exit status
      wait(&status1);
      printf(1, "Child 1 exited with status: %d\n", status1);

      // Wait for the second child and get its exit status
      wait(&status2);
      printf(1, "Child 2 exited with status: %d\n", status2);
    }
  }

  exit(0);
}
