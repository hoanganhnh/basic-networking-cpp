#include<winsock2.h>
#include<ws2tcpip.h>
#include<bits/stdc++.h>
#include "student.h"
#define DEFAULT_BUFLEN 512

using namespace std;

int main(){
	int iResult = 0;
	WSADATA wsaData;
	if(WSAStartup(MAKEWORD(2,2), &wsaData) != 0){
		cout << "\nWINSOCK: khoi tao that bai\n";
		WSACleanup();
		return 0;
	}else {
		cout << "\nWINSOCK: khoi tao thanh cong\n";
	}
	
	SOCKET in = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	
	u_short port = 8081;
	const char *IP = "127.0.0.1";
	SOCKADDR_IN svrAddr;
	int svrAddrLen = sizeof(svrAddr);
	svrAddr.sin_family = AF_INET;
	svrAddr.sin_port = htons(port);
	svrAddr.sin_addr.s_addr = inet_addr(IP);
	
	iResult = bind(in, (SOCKADDR*) &svrAddr, svrAddrLen);
	if(iResult == SOCKET_ERROR){
		printf("bind failed with error: %d\n", WSAGetLastError());
		closesocket(in);
		WSACleanup();
		return 1;
	}
	
	sockaddr_in client;
	int clientLength = sizeof(client);
	char buf[1024];
	
	char recvbuf[DEFAULT_BUFLEN];
	float iSendResult;
	float recvbuflen = DEFAULT_BUFLEN;
	
	do{
		iResult = recvfrom(in, buf, 1024, 0, (struct sockaddr*) &client, &clientLength);
		buf[iResult]='\0';
		string id = buf;
		cout << "\nMa sinh vien nhan duoc: " << id;
		
		Student std;
		std.setId(id);
		string kq = std.Check();
		iSendResult = sendto(in, kq.c_str(), kq.size(), 0, (struct sockaddr *)&client, clientLength);
	}while(iResult > 0);
	closesocket(in);
	WSACleanup();
}
