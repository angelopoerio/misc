/*
  Trace syscalls of a process thanks to ptrace() - Author: Angelo Poerio <angelo.poerio@gmail.com>
  It is intended for x86_64 Linux boxes!
  You can get a list of syscall here: https://filippo.io/linux-syscall-table/
*/

#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/user.h>

#include <syscall.h>

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {   
  pid_t child;

  if (argc == 1) {
    exit(0);
  }

  char* chargs[argc];
  int i = 0;

  while (i < argc - 1) {
    chargs[i] = argv[i+1];
    i++;
  }
  chargs[i] = NULL;

  child = fork();
  if(child == 0) {
    ptrace(PTRACE_TRACEME, 0, NULL, NULL);
    execvp(chargs[0], chargs);
  } else {
    int status;

    while(waitpid(child, &status, 0) && ! WIFEXITED(status)) {
      struct user_regs_struct regs; 
      ptrace(PTRACE_GETREGS, child, NULL, &regs);
      printf("SYSCALL CALLED: 0x%llx\n",regs.orig_rax);
      ptrace(PTRACE_SYSCALL, child, NULL, NULL);
    }
  }
  exit(0);
}
