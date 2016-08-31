#!/bin/bash

# a simple script to monitor a MAC!
# Author: Angelo Poerio

if [ -z $1 ]
then
  echo "Usage $0 arp_to_monitor"
  echo "Example: $0 30:b5:c2:b2:ed:38"
  exit 1
fi

mac=$1
echo "Monitoring for $1"

while true; do cat /proc/net/arp |awk -v mac_to_match=$1 '{if(NR > 1) { if($4 == mac_to_match) { system("mail -s "monitored MAC joined the network" some@some.com"); } } }';sleep 5; done

