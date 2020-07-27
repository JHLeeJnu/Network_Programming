#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>

int make_socket(uint16_t port)
{
	int 				sock;
	struct sockaddr_in 	name;				// �����׽��� 
	
	sock = socket(PF_INET, SOCK_STREAM, 0);	// ����TCP������
	
	if(sock < 0){							// ����TCP������ʧ�� 
		perror("socket");
		exit(EXIT_FAILURE);
	} 
	
	name.sin_family = AF_INET;					// IPv4Э�� 
	name.sin_port = htons(port);				// �󶨶˿� 
	name.sin_addr.s_addr = htons(INADDR_ANY);	// �󶨱���IP��ַ
	
	if(bind(sock, (struct (sockaddr *) &name, 0) < 0){	// ���׽��ֺ������� 
		perror("bind");
		exit(EXIT_FAILURE); 
	} 
	
	return sock;
}

int main(int argc, char ** argv){
	int sockfd = make_socket(12345);	// �����˿�Ϊ12345���׽���
	exit(0); 
}
