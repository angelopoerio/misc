#!/bin/bash
qemu-system-x86_64 -initrd initramfs.cpio.gz -kernel linux_image/arch/x86_64/boot/bzImage
