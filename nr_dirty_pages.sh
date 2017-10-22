#!/bin/bash

# Parse /proc/vmstat to get the number of dirty pages (pages that must be written to disks)
# Tunable parameters: sysctl -a|grep dirty

cat /proc/vmstat |grep "^nr_dirty\s[0-9]*$"|cut -d' ' -f 2
