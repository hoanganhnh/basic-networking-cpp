#include<winsock2.h>
#include<windows.h>
#include<ws2tcpip.h>
#include<bits/stdc++.h>

#define DEFAULT_BUFLEN 512

using namespace std;

int main(int argc, char **argv){
	WSADATA wsaData;
	int iResult;
	
	iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
	if(iResult != 0){
		printf("WSAStartup failed with error: %d\n", iResult);
		return 1;
	}
	cout << "WSAStartup OK" << endl;
	
	SOCKET out = socket(AF_INET, SOCK_DGRAM, 0);
	
	int port = 8081;
	const char *IP = "127.0.0.1";
	SOCKADDR_IN svrAddr;
	int svrAddrLen = sizeof(svrAddr);
	svrAddr.sin_family = AF_INET;
	svrAddr.sin_port = htons(port);
	svrAddr.sin_addr.s_addr = inet_addr(IP);
	
	char recvbuf [DEFAULT_BUFLEN];
	int recvbuflen = DEFAULT_BUFLEN;
	char strRecvFromServer[256];
	
	float a, b;
	while(1){
		cout << "\nNhap so a: ";
		cin >> a;
		cout << "\nNhap so b: ";
		cin >> b;
		string s1 = to_string(a);
		string s2 = to_string(b);
		sendto(out, s1.c_str(), s1.size(), 0, (struct sockaddr*) &svrAddr, svrAddrLen);
		sendto(out, s2.c_str(), s2.size(), 0, (struct sockaddr*) &svrAddr, svrAddrLen);
		
		recvfrom(out,strRecvFromServer,256,0,(struct sockaddr*) &svrAddr,&svrAddrLen);
		cout << "\nNhan tu Sever tong cua 2 so la: " << strRecvFromServer <<endl;
	}
	closesocket(out);
	WSACleanup();
	return 0;
}
