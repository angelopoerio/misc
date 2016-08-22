#!/bin/bash
cc init.c -static -o initramfs/init # statically linked so we do not have to care about dinamic libraries!
cd initramfs
find . -print0 \
    | cpio --null -ov --format=newc \
    | gzip -9 > ../initramfs.cpio.gz

