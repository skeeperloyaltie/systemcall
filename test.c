// Inside test.c

// Inside test.c

#include "types.h"
#include "user.h"
#include "time.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pid = fork();
    if (pid == 0) {
        // Child process: execute uniq or head
        char *argv[] = { "uniq", "file.txt", 0 };
        exec("uniq", argv);
    } else if (pid > 0) {
        // Parent process: wait for the child and get process information
        int wtime, rtime;
        waitx(&wtime, &rtime);
        printf( "Creation Time: %d\nTotal Time: %d\n", (int)wtime, (int)rtime);
    } else {
        printf("Fork failed\n");
    }

    exit(1);
}
