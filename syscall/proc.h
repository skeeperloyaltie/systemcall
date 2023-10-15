// proc.h

#ifndef _PROC_H_
#define _PROC_H_

// #include "param.h"
// #include "spinlock.h"

struct context {
  int eip;
  int esp;
  int ebx;
  int ecx;
  int edx;
  int esi;
  int edi;
  int ebp;
};

enum procstate { UNUSED, EMBRYO, SLEEPING, RUNNABLE, RUNNING, ZOMBIE };

struct proc {
  char *mem;                // Start of process memory (kernel address)
  uint sz;                  // Size of process memory (bytes)
  char *kstack;             // Bottom of kernel stack for this process
  enum procstate state;     // Process state
  int pid;                  // Process ID
  struct proc *parent;      // Parent process
  void *chan;               // If non-zero, sleeping on chan
  int killed;               // If non-zero, have been killed
  struct file *ofile[NOFILE];  // Open files
  struct inode *cwd;        // Current directory
  struct context context;   // Switch here to run process
  struct trapframe *tf;     // Trap frame for the current interrupt
  int exit_status;          // Exit status of the terminated process
};

extern struct proc proc[NPROC];
extern struct spinlock proc_table_lock;

#endif // _PROC_H_
