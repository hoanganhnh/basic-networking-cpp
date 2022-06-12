#include <winsock2.h>
#include <ws2tcpip.h>
#include<bits/stdc++.h>

#define DEFAULT_BUFLEN 512

using namespace std;


// Main entry point into the server
int main()
{
	 int iResult=0;
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

	// Create a socket, notice that it is a user datagram socket (UDP)
	SOCKET in = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  //Xac dinh dinh danh ung dung 
    u_short port = 8081;
    const char *IP = "127.0.0.1";
    SOCKADDR_IN svrAddr;
	int svrAddrLen = sizeof(svrAddr);
	svrAddr.sin_family = AF_INET;
	svrAddr.sin_port = htons(port);
	svrAddr.sin_addr.s_addr = inet_addr(IP);
    // Setup the TCP listening socket
    iResult = bind( in, (SOCKADDR*) &svrAddr, svrAddrLen);
    if (iResult == SOCKET_ERROR) {
        printf("bind failed with error: %d\n", WSAGetLastError());
        closesocket(in);
        WSACleanup();
        return 1;
    }
	////////////////////////////////////////////////////////////
	// MAIN LOOP SETUP AND ENTRY
	////////////////////////////////////////////////////////////

	sockaddr_in client; // Use to hold the client information (port / ip address)
	int clientLength = sizeof(client); // The size of the client information
	char buf[1024];

	
//    char recvbuf[DEFAULT_BUFLEN];
	float iSendResult;
	float recvbuflen = DEFAULT_BUFLEN;
	float a, b;

	do {
	    iResult = recvfrom(in, buf, 1024, 0,(struct sockaddr *)&client, &clientLength); 
	    buf[iResult] = '\0';
	    a = atoi(buf);
	    
	    iResult = recvfrom(in, buf, 1024, 0,(struct sockaddr *)&client, &clientLength); 
	    buf[iResult] = '\0';
	    b = atoi(buf);
	    
	    cout << "\nNhan a la: " << a << endl;
		cout << "\nNhan b la: " << b << endl;
		
		float c = a + b;
		string kq = to_string(c);
		
        iSendResult = sendto(in, kq.c_str(), kq.size(), 0,(struct sockaddr *)&client, clientLength);

	        
	} while (iResult > 0);

	// Close socket
	closesocket(in);

	// Shutdown winsock
	WSACleanup();
}





