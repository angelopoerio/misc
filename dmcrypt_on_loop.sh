#!/bin/bash

# Encrypt loopdevice with dmcrypt
# Author: Angelo Poerio <angelo.poerio@gmail.com>

dd if=/dev/zero bs=100MB count=2 of=/tmp/disk1.img 
losetup /dev/loop1 /tmp/disk1.img
cryptsetup -s 512 luksFormat --type luks2  /dev/loop1
cryptsetup open /dev/loop1 encVol
mkfs -t ext4 /dev/mapper/encVol

# you can now mount the ecrypted file system /dev/mapper/encVol everywhere and start using it
