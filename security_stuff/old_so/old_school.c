/*
	A simple uber exploitable program.
	How to test:
	1) Disable ALSR: echo "0" > /proc/sys/kernel/randomize_va_space 
	2) Compile with executable stack and stack smashing off: cc old_school.c -o old_school -zexecstack -fno-stack-protector -g
*/

#include <string.h>

void go(char *data) {
    char name[128];

    strcpy(name, data);
}

int main(int argc, char **argv) {
    go(argv[1]);
}
