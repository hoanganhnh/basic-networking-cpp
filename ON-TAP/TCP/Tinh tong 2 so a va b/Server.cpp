#include <winsock2.h>
#include <ws2tcpip.h>
#include<bits/stdc++.h>

#define DEFAULT_BUFLEN 512

using namespace std;

int main() {
	
    int iResult=0;
    int iResult2=0;
    
/*****************************************************/
/*    Khoi tao Winsock 2.2
/*****************************************************/
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
    	cout << "\nWINSOCK: Khoi tao that bai\n";
    	WSACleanup();
    	return 0;
	}	else	{
		cout << "\nWINSOCK: Khoi tao thanh cong\n";
	}
/*****************************************************/
/*    Creating a Socket for the Server: s */
/*****************************************************/
	SOCKET s = INVALID_SOCKET;
	// Create a SOCKET for the server to listen for client connections
	s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (s == INVALID_SOCKET) {
	    printf("Error at socket(): %ld\n", WSAGetLastError());
	    WSACleanup();
	    return 1;
	}
/*****************************************************/
/*    Binding a Socket*/
/*****************************************************/
	//Xac dinh dinh danh ung dung 
    u_short port = 81;
    const char *IP = "127.0.0.1";
    SOCKADDR_IN svrAddr;
	int svrAddrLen = sizeof(svrAddr);
	svrAddr.sin_family = AF_INET;
	svrAddr.sin_port = htons(port);
	svrAddr.sin_addr.s_addr = inet_addr(IP);
    // Setup the TCP listening socket
    iResult = bind( s, (SOCKADDR*) &svrAddr, svrAddrLen);
    if (iResult == SOCKET_ERROR) {
        printf("bind failed with error: %d\n", WSAGetLastError());
        closesocket(s);
        WSACleanup();
        return 1;
    }
    cout<<"ListenSocket: "<<s<<endl;
    
/*****************************************************/
/*    Listening on a Socket*/
/*****************************************************/
	
	if ( listen( s, 5 ) == SOCKET_ERROR ) {
	    printf( "Listen failed with error: %ld\n", WSAGetLastError() );
	    closesocket(s);
	    WSACleanup();
	    return 1;
	}
    cout<<"Listening ... "<<endl;
/*****************************************************/
/*    Accepting a Connection*/
/*****************************************************/
	//Create a temporary SOCKET object called ClientSocket for accepting connections from clients.
	SOCKET sa;
	sa = INVALID_SOCKET;

	// Accept a client socket
    SOCKADDR_IN cliAddr;
	int cliAddrLen = sizeof(cliAddr);
	sa = accept(s, (SOCKADDR*) &cliAddr, &cliAddrLen);
    cout<<"Nhan du lieu tu IP:"<< inet_ntoa(cliAddr.sin_addr) << " port: "<< ntohs(cliAddr.sin_port)<<endl;
	
	if (sa == INVALID_SOCKET) {
	    printf("accept failed: %d\n", WSAGetLastError());
	    closesocket(s);
	    WSACleanup();
	    return 1;
	}
    cout<<"ClientSocket: "<<sa<<endl;
/*****************************************************/
/*    Receiving and Sending Data on the Server*/
/*****************************************************/
	
	char recvbuf[DEFAULT_BUFLEN];
	char recvbuf2[DEFAULT_BUFLEN];
	int iSendResult;
	int iSendResult2;
	int recvbuflen = DEFAULT_BUFLEN;
	int recvbuflen2 = DEFAULT_BUFLEN;
	
	// Receive until the peer shuts down the connection
	do {

	    iResult = recv(sa, recvbuf, recvbuflen, 0);
	    recvbuf[iResult] = '\0';
	    int a = atoi(recvbuf);
	    iResult = recv(sa, recvbuf, recvbuflen, 0);
	     recvbuf[iResult] = '\0';
    	int b = atoi(recvbuf);
    	
    	int c = a + b;
    	string kq = to_string(c);
    	iSendResult = send(sa, kq.c_str(), kq.length(), 0);
	
	} while (iResult > 0);
/*****************************************************/
/*    Disconnecting the Server*/
/*****************************************************/
	// shutdown the send half of the connection since no more data will be sent
	iResult = shutdown(sa, SD_SEND);
	if (iResult == SOCKET_ERROR) {
	    printf("shutdown failed: %d\n", WSAGetLastError());
	    closesocket(sa);
	    WSACleanup();
	    return 1;
	}
	// cleanup
	closesocket(sa);
	
	closesocket(s);
	WSACleanup();

	
getchar();
return 0;
}

