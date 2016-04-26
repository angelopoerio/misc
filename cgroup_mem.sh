# playing with memory cgroup

#!/bin/bash
current_user=$(whoami)
cgroup_name="cgroup_test"
sudo cgcreate -a $current_user:$current_user -t $current_user:$current_user  -g memory:$cgroup_name
echo 10000 > /sys/fs/cgroup/memory/$cgroup_name/memory.limit_in_bytes # 10MB
cat <<- _EOF_ > mem_alloc.c
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
	int c = 0;
	while(1){
		printf("[%d] asking for 2mb\n",c);
		malloc(2 * 1024 * 1024);
		c++;
	}
	return 0;
}
_EOF_

cc mem_alloc.c -o mem_alloc

# execute the program in the cgroup
cgexec -g memory:$cgroup_name ./mem_alloc
