#!/bin/bash
mkdir initramfs
mkdir initramfs/{bin,etc,proc,sbin,sys,usr}
cc init.c -static -o initramfs/init # statically linked so we do not have to care about dynamic libraries!
cd initramfs
find . -print0 \
    | cpio --null -ov --format=newc \
    | gzip -9 > ../initramfs.cpio.gz

