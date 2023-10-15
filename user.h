// Inside user.h

#ifndef _USER_H_
#define _USER_H_
#include "syscall.c"
#include <stdio.h>
#include <stdlib.h>
// #include <argptr.h>
// #include <myproc.h>
#include <stdlib.h>

// Inside user.c

int exec(char *path, char **argv) {
    int pid = fork();
    if (pid == 0) {
        // Child process
        if (execv(path, argv) < 0) {
            printf("exec failed\n");
            exit(1);
        }
    } else if (pid > 0) {
        // Parent process
        wait(); // Wait for the child to complete
    } else {
        printf("fork failed\n");
    }

    return pid;
}

// Inside user.c

int waitx(int *wtime, int *rtime) {
    int pid = wait();
    if (pid < 0) {
        printf("wait failed\n");
        return -1;
    }

    // Get process information using a system call
    gettime(wtime, rtime);

    return pid;
}




int fork(void);
int exec(char *path, char *argv[]);
int wait(void);
int waitx(int *wtime, int *rtime);
// void exit(void);

#endif // _USER_H_
