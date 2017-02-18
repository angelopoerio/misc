#!/bin/bash
# Create a LVM volume on loop devices
# Run as root!
# Author: Angelo Poerio <angelo.poerio@gmail.com>

dd if=/dev/zero bs=100MB count=2 of=/tmp/disk1.img 
dd if=/dev/zero bs=100MB count=2 of=/tmp/disk2.img
losetup /dev/loop0 /tmp/disk1.img
losetup /dev/loop1 /tmp/disk2.img
pvcreate /dev/loop0 /dev/loop1
vgcreate vol_on_loop /dev/loop0 /dev/loop1
lvcreate -L 200M -n lv_loop vol_on_loop

