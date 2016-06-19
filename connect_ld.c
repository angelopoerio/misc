/*
	Avoid connection to some ip addresses using LD_PRELOAD trick.
	Compile: gcc -o connect_ld.so -shared connect_ld.c -ldl -fPIC 
	Use (example): LD_PRELOAD=$(pwd)/connect_ld.so  nc -vv www.google.it 80 
	Author: Angelo Poerio <angelo.poerio@gmail.com>
*/


#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>

#include <errno.h>

#define __USE_GNU
#include <dlfcn.h>

#define BLOCKED_IPS 2 /* update with the number of ip strings in blocked_list */

char *blocked_list[] = {
	"216.58.210.227", 
	"77.238.184.150",
};


int connect(int sockfd, const struct sockaddr *serv_addr, socklen_t addrlen) {
	static int (*connect_real)(int, const  struct sockaddr*, socklen_t) = NULL; 
	char buffer[INET_ADDRSTRLEN];
	int addr_len = sizeof(struct sockaddr), conn_flag = 1, ip_cnt;
	
  	if (!connect_real) 
		connect_real=dlsym(RTLD_NEXT,"connect");

  	if (serv_addr->sa_family==AF_INET){
		getnameinfo(serv_addr,addr_len,buffer,sizeof(buffer),0,0,NI_NUMERICHOST);
		for(ip_cnt = 0;ip_cnt < BLOCKED_IPS;ip_cnt++) {
			if(strcmp(buffer, blocked_list[ip_cnt]) == 0) {
				conn_flag = 0;
				break;
			}
		}
	}

  	return conn_flag ? connect_real(sockfd,serv_addr,addrlen) : EACCES;
}
