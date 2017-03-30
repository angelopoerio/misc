#!/bin/bash

# generate a SSL certificate avoiding the interactive prompt
# Author: Angelo Poerio <angelo.poerio@gmail.com>

temp_path=$(mktemp)
 # change as you need
cat <<_EOF1_>$temp_path 
IT
dummy state
dummy locality
dummy org
dummy unit
dummy cn
dummy email
_EOF1_

openssl req -newkey rsa:2048 -nodes -keyout domain.key -x509 -days 365 -out domain.crt < $temp_path
rm -f $temp_path
