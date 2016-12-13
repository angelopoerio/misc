#!/bin/bash

# Display TCP connections ordered by ascending RTT (round time trip in microseconds)
# Author: Angelo Poerio <angelo.poerio@gmail.com>

ip tcp_metrics show | awk '{print $1 " " $5;}'|tr 'us' ' '|sort -k 2
