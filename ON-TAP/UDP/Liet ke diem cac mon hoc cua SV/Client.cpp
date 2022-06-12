#include<winsock2.h>
#include<windows.h>
#include<ws2tcpip.h>
#include<bits/stdc++.h>
#include "student.h"
#define DEFAULT_BUFLEN 512
using namespace std;

int main(int argc, char **argv){
	WSADATA wsaData;
	int iResult;
	
    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        return 1;
    }
	cout<<"WSAStartup OK"<<endl;
	
	SOCKET out = socket(AF_INET, SOCK_DGRAM, 0);

	int port=8081;
	const char *IP="127.0.0.1";//"10.170.72.81"
	SOCKADDR_IN svrAddr;
	int svrAddrLen = sizeof(svrAddr);
	svrAddr.sin_family = AF_INET;
	svrAddr.sin_port = htons(port);
	svrAddr.sin_addr.s_addr = inet_addr(IP);


    char recvbuf[DEFAULT_BUFLEN];
    int recvbuflen = DEFAULT_BUFLEN;
    char strRecvFromServer[256];
    string id;
    while(1){
    	cout << "\nNhap ma sinh vien can tim: ";
    	getline(cin, id);
    	sendto(out, id.c_str(), id.size(), 0,(struct sockaddr*) &svrAddr,svrAddrLen);
    	
    	recvfrom(out,strRecvFromServer,256,0,(struct sockaddr*) &svrAddr,&svrAddrLen);
    	
    	if(strRecvFromServer == id){
    		Student  std;
    		std.setId(id);
    		std.Check();
    		std.Display();
		}else {
			cout << "\nSinh vien khong ton tai!";
		}
    	
	}
	closesocket(out);
	WSACleanup();
	return 0;

}
