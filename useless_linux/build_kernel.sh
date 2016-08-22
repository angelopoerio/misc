#!/bin/bash
wget https://www.kernel.org/pub/linux/kernel/v4.x/linux-4.6.tar.xz # get kernel source
tar xJf linux-4.6.tar.xz
cd linux-4.6
make O=../linux_image x86_64_defconfig
make O=../linux_image
