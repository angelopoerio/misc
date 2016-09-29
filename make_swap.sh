#!/bin/bash

# one liner to add swap space - Angelo Poerio <angelo.poerio@gmail.com>

fallocate -l 512M /mnt/swap ; \
dd if=/dev/zero of=/mnt/swap bs=512 count=1048576 \
 ; mkswap /mnt/swap ; swapon /mnt/swap ; swapon -s ; free -m
