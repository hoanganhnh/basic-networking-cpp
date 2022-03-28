#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <fstream>
#include <iostream>

#include "E:\owner-project\server-client\TCP\student-info\student.cpp"

#define DEFAULT_BUFLEN 512

using namespace std;

string convertToString(char* a, int size) {
    int i;
    string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}

int main() {
	
    int iResult=0;
    
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
	
	if (listen(s, 5) == SOCKET_ERROR) {
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
	int iSendResult;
	int recvbuflen = DEFAULT_BUFLEN;
	
	// Receive until the peer shuts down the connection
	string id;
	string name;

	// Init class Student info
	Student st;
	do {

		iResult = recv(sa, recvbuf, recvbuflen, 0);
		if (iResult) {
			recvbuf[iResult] = '\0';
			cout<<"\nResult: "<< recvbuf << endl;
			name = recvbuf;
			cout << "name: "<< name;
			string s = "Successfull!";
			int n = s.length();
			char char_array[n + 1];
		
			strcpy(char_array, s.c_str());
			iSendResult = send(sa, char_array, n + 1, 0);
			
			st.modify_student(name);
		}


	    // if (iResult > 0) {
	    //     recvbuf[iResult] = '\0';
		// 	cout<<"\nResult: "<< recvbuf <<endl;
	    //     // printf("Bytes received: %d\n", iResult);
		// 	if (convertToString(recvbuf, iResult) == (username + password)) {
		// 		string s = "Successfull!";
		// 		int n = s.length();
		// 		char char_array[n + 1];
			
		// 		strcpy(char_array, s.c_str());
		// 		iSendResult = send(sa, char_array, n + 1, 0);
		// 	} else {
		// 		string s = "Please check username or password!";
			
		// 		int n = s.length();
		// 		char char_array[n + 1];
			
		// 		strcpy(char_array, s.c_str());
		// 		iSendResult = send(sa, char_array, n + 1, 0);
		// 	}
	    //     // Echo the buffer back to the sender
	    //     //recvbuf[recvbuf.size()]='\0';
	
	        if (iSendResult == SOCKET_ERROR) {
	            printf("send failed: %d\n", WSAGetLastError());
	            closesocket(sa);
	            WSACleanup();
	            return 1;
	        }
	    //     // printf("Bytes sent: %d\n", iSendResult);
	    // } else if (iResult == 0) {
	    //     printf("Connection closing...\n");
		// } else {
	    //     printf("recv failed: %d\n", WSAGetLastError());
	    //     closesocket(sa);
	    //     WSACleanup();
	    //     return 1;
	    // }

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


