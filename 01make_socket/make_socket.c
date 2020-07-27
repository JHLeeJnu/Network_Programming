#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>

int make_socket(uint16_t port)
{
	int 				sock;
	struct sockaddr_in 	name;				// 创建套接字 
	
	sock = socket(PF_INET, SOCK_STREAM, 0);	// 创建TCP描述字
	
	if(sock < 0){							// 创建TCP描述字失败 
		perror("socket");
		exit(EXIT_FAILURE);
	} 
	
	name.sin_family = AF_INET;					// IPv4协议 
	name.sin_port = htons(port);				// 绑定端口 
	name.sin_addr.s_addr = htons(INADDR_ANY);	// 绑定本机IP地址
	
	if(bind(sock, (struct (sockaddr *) &name, 0) < 0){	// 绑定套接字和描述字 
		perror("bind");
		exit(EXIT_FAILURE); 
	} 
	
	return sock;
}

int main(int argc, char ** argv){
	int sockfd = make_socket(12345);	// 建立端口为12345的套接字
	exit(0); 
}
