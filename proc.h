// Inside proc.h

#ifndef _PROC_H_
#define _PROC_H_

#include "types.h"

// Process state enum (existing definition)
enum procstate { UNUSED, EMBRYO, SLEEPING, RUNNABLE, RUNNING, ZOMBIE };

// Process structure (add the new time-related fields)
struct proc {
  // ... other fields ...
  uint creation_time;
  uint end_time;
  uint total_time;
  // ... other fields ...
};

// ... existing definitions ...

#endif // _PROC_H_
