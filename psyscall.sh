# Author: Angelo Poerio <angelo.poerio@gmail.com>
# This bash script let you know the current syscall the given process is executing.
# Example usage: sudo ./psyscall $(pidof firefox)
# Tested on Ubuntu

#!/bin/bash

print_syscall_name() {
	# resolve syscall names in C header files
	if [ $(uname -p) = "x86_64" ]
	then
		sys_header=$(find /usr/include -iname "unistd_64.h")
	else
		sys_header=$(find /usr/include -iname "unistd_32.h")
	fi
		captured_syscall=$(grep "^#define __NR_.* $1$" $sys_header|sed 's/#define __NR_//g'|cut -f 1 -d ' ')
	echo "It is executing: $captured_syscall()"
	exit 0
}

if [ -z $1 ]
then
	echo "Usage: $0 pid"
	exit 1
fi

if [ $(id -u) -ne 0 ]
then
	echo "Run as root"
	exit 1	
fi

syscall_path=/proc/$1/syscall

if [ ! -f $syscall_path ]
then
	echo "process not existing"
	exit 1
else
	syscall=$(cat $syscall_path|cut -d ' '  -f 1)
	echo "Process started with cmdline: $(cat /proc/$1/cmdline)"
	print_syscall_name $syscall
	exit 0
fi
