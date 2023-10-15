// Inside syscall.c

#include "types.h"
#include "proc.h"
#include "syscall.h"
#include "stdarg.h"
// #include "myproc.h"


// ... other includes ...

// Modify sys_waitx to return process information
int
sys_waitx(void) {
    int *wtime, *rtime;

    if (argptr(0, (void*)&wtime, sizeof(*wtime)) < 0 || argptr(1, (void*)&rtime, sizeof(*rtime)) < 0)
        return -1;

    // ... existing code ...

}


// int
gettime(int *wtime, int *rtime) {
    struct proc *p = myproc();

    // Check if process is null
    if (p == 0)
        return -1;

    // Assign the values of creation time and total time to the provided pointers
    *wtime = p->creation_time;
    *rtime = p->total_time;

    return 0;
}
