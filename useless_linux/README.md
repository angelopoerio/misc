# Useless Linux
  This repository contains a collection of scripts to build a minimal GNU/Linux system.
  The initrd does not contains any environment you can use to boot a real user space but just
  a statically linked init program that only prints the string "...Useless..." every 10 seconds.
  It is only for learning purpose!

# Scripts
*  build_initrd.sh - build the initrd 
*  build_initrd_busybox.sh - use this script to generate an initrd with busybox (you get a minimal shell)
*  build_kernel.sh - download and compile a working kernel
*  run_system.sh   - run the build system in qemu
*  useless.sh      - utility script to automate all the steps

# Author
  Angelo Poerio - <angelo.poerio@gmail.com>
