#!/bin/bash

# Author: Angelo Poerio <angelo.poerio@gmail.com>
# Try to list the log files of an application
# Example usage: sudo ./list_logs.sh $(pidof mysqld)

print_logs() {
	for file in $(ls $1)
	do
		real_path=$(readlink $1/$file)
		if [[ -f $real_path &&  "${real_path}" == *.log* ]]
		then
			echo $real_path
		fi
	done
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

fd_path=/proc/$1/fd

if [ ! -d $fd_path ]
then
	echo "process not existing"
	exit 1
else
	echo "Process logs: "
	print_logs $fd_path
	exit 0
fi


