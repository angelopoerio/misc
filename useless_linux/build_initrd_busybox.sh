#!/bin/bash
#get http://busybox.net/downloads/busybox-1.23.2.tar.bz2
tar xjf busybox-1.23.2.tar.bz2
mkdir initramfs
mkdir initramfs/{bin,etc,proc,sbin,sys,usr,dev}
mkdir busybox_image
cd busybox-1.23.2
make O=../busybox_image defconfig
sed -i "s/.*CONFIG_STATIC.*/CONFIG_STATIC=y/" ../busybox_image/.config
cd ../busybox_image
make
make install
cp -a ../busybox_image/_install/* ../initramfs
cat <<- _EOF_ > ../initramfs/init
!/bin/sh
mount -t proc none /proc
mount -t sysfs none /sys
mount -t devtmpfs none /dev
exec /bin/sh
_EOF_
chmod +x ../initramfs/init
cd ../initramfs
rm linuxrc # entry point is init script
find . -print0 \
    | cpio --null -ov --format=newc \
    | gzip -9 > ../initramfs.cpio.gz

