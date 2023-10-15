// proc.c

// #include "types.h"
// #include "defs.h"
// #include "param.h"
// #include "spinlock.h"
#include "proc.h"

int wait(int *status) {
  struct proc *p;
  int havekids, pid;

  acquire(&proc_table_lock);

  for (;;) {
    havekids = 0;
    for (p = proc; p < &proc[NPROC]; p++) {
      if (p->parent != myproc())
        continue;
      
      havekids = 1;
      if (p->state == ZOMBIE) {
        pid = p->pid;
        if (status != NULL)
          *status = p->exit_status;
        kfree(p->kstack);
        p->kstack = 0;
        freevm(p->mem);
        p->pid = 0;
        p->parent = 0;
        p->state = UNUSED;
        release(&proc_table_lock);
        return pid;
      }
    }

    if (!havekids || myproc()->killed) {
      release(&proc_table_lock);
      return -1;
    }

    sleep(myproc(), &proc_table_lock);
  }
}
