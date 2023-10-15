// Inside proc.c

#include "types.h"
#include "defs.h"
#include "param.h"
#include "mmu.h"
#include "proc.h"
#include "x86.h"

// ... other includes ...

// Inside allocproc() when a process is created
struct proc* allocproc(void) {
  // ... existing code ...

  // Update the creation time
  p->creation_time = ticks;

  // ... existing code ...
}

// Inside exit() when a process is terminated
void exit(void) {
  // ... existing code ...

  // Update the end time and total time
  proc->end_time = ticks;
  proc->total_time = proc->end_time - proc->creation_time;

  // ... existing code ...
}
