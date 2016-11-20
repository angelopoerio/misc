/*
	An example sandbox using unshare() and network/mount namespaces 
	Authors: Angelo Poerio <angelo.poerio@gmail.com>
*/

#define _GNU_SOURCE
#include <sys/utsname.h>
#include <sched.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mount.h>
 
static void mount_r(const char *dir) {
   if(mount(dir, dir, NULL, MS_BIND|MS_REC, NULL) < 0) {
                printf("could not --bind mount %s\n",dir);
		exit(1);
   }
                 
   if (mount(NULL, dir, NULL, MS_BIND|MS_REMOUNT|MS_RDONLY|MS_REC, NULL) < 0) {
                printf("could not remount in ro %s\n",dir);
   		exit(1);
   }
}
 
static void mount_tmp(const char *dir) {
    if (mount(NULL, dir, "tmpfs", 0, NULL) < 0) {
        printf("could not mount tmpfs on %s\n",dir);
    	exit(1);
    }
}
 
int main(int argc, char **argv) {
    const char *dirs[] = {"/sbin", "/bin", "/lib", "/lib64", "/usr", "/etc"};
    char *shell[] = {"/bin/bash", NULL};
    int i;
	
    if (unshare(CLONE_NEWNS | CLONE_NEWNET) < 0) {
        printf("unshare() failed\n"); 
	exit(1);
    }
 
    if (mount(NULL, "/", NULL, MS_SLAVE | MS_REC, NULL) < 0) {
        printf("failed remount / as --slave");
	exit(1);
    }
    
    for(i = 0;i < 6;i++)
	mount_r(dirs[i]);


    mount_tmp("/sandbox"); /* be sure you have this directory */
     
    chdir("/sandbox");
    execvp(shell[0], shell);
    return 0;
}
