# Author: Angelo Poerio <angelo.poerio@gmail.com>
# Description: show the I/O scheduler of each block device in the system
# Learn more: https://www.kernel.org/doc/Documentation/block/switching-sched.txt

import glob

block_devs = "/sys/block/*"

for dev in glob.glob(block_devs):
    with open("{}/queue/scheduler".format(dev)) as sched_fn:
        print "DEVICE: {0}, SCHEDULER: {1}".format(dev, sched_fn.read())
