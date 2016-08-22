#!/bin/bash
echo "building initramfs ..."
./build_initrd.sh
echo "building kernel ..."
./build_kernel.sh
echo "run it!"
./run_system.sh

