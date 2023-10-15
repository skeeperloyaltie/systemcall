// sysproc.c

// #include "types.h"
// #include "defs.h"
// #include "param.h"
// #include "mmu.h"
#include "proc.h"
// #include "x86.h"
#include "syscall.h"
// #include "traps.h"

int sys_fork(void) {
  return fork();
}

int sys_exit(void) {
  int status;
  if (argint(0, &status) < 0)
    return -1;

  acquire(&proc_table_lock);
  myproc()->exit_status = status;
  release(&proc_table_lock);

  exit(status);
  return 0; // Not reached
}

int sys_wait(void) {
  int *status;
  if (argptr(0, (char**)&status, sizeof(int*)) < 0)
    return -1;

  return wait(status);
}

int sys_kill(void) {
  int pid;

  if (argint(0, &pid) < 0)
    return -1;

  return kill(pid);
}

int sys_getpid(void) {
  return myproc()->pid;
}

int sys_sbrk(void) {
  int addr;
  int n;

  if (argint(0, &n) < 0)
    return -1;

  addr = myproc()->sz;
  if (growproc(n) < 0)
    return -1;

  return addr;
}

int sys_sleep(void) {
  int n;
  uint ticks0;

  if (argint(0, &n) < 0)
    return -1;

  acquire(&tickslock);
  ticks0 = ticks;
  while (ticks - ticks0 < n) {
    if (myproc()->killed) {
      release(&tickslock);
      return -1;
    }
    sleep(myproc(), &tickslock);
  }
  release(&tickslock);
  return 0;
}

int sys_kill(void) {
  int pid;

  if (argint(0, &pid) < 0)
    return -1;

  return kill(pid);
}
