#!/bin/bash

# get swap space used by processes running on the system
# Author: Angelo Poerio <angelo.poerio@gmail.com>

for pid_file in /proc/[0-9]*
do
	cat $pid_file/cmdline 
	awk '/VmSwap/ {print " " $2 " " $3}' $pid_file/status
done
