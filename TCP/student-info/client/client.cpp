#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>

// @note: change absolute path
// #include "E:\owner-project\server-client\TCP\student-info\student.cpp"

#define DEFAULT_BUFLEN 512

using namespace std;

int main(int argc, char **argv) {
    WSADATA wsaData;
    int iResult;

	/*****************************************************/
	/*    Khoi tao Winsock 2.2
	/*****************************************************/
    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        return 1;
    }
	cout<<"WSAStartup OK"<<endl;
	/*****************************************************/
	/*    Creating a Socket for the Server: ListenSocket */
	/*****************************************************/
    SOCKET ConnectSocket = INVALID_SOCKET;
	ConnectSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (ConnectSocket == INVALID_SOCKET) {
        printf("socket failed with error: %ld\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }
	cout<<"ConnectSocket = socket OK"<<endl;
	/*****************************************************/
	/*    */
	/*****************************************************/
	//Xac dinh dinh danh ung dung tren server
	int port=81;
	const char *IP="127.0.0.1";//"10.170.72.81"
	SOCKADDR_IN svrAddr;
	int svrAddrLen = sizeof(svrAddr);
	svrAddr.sin_family = AF_INET;
	svrAddr.sin_port = htons(port);
	svrAddr.sin_addr.s_addr = inet_addr(IP);

	if (connect(ConnectSocket, (SOCKADDR*) &svrAddr, svrAddrLen) == SOCKET_ERROR) {
		printf ("\nCLIENT: Ket noi that bai\n");
		system("pause");
		WSACleanup();
	} else{
		printf("\nCLIENT: Ket noi thanh cong\n");
		printf("-----------------------------------------------------------------------\n");
	}

    char recvbuf[DEFAULT_BUFLEN];
    int recvbuflen = DEFAULT_BUFLEN;
    char connectedClient[256];

	//Gui nhan du lieu

	string id;
	string age;
	string name;
	string password;
	int option;
	while(1) {
		// @todo: fix send data from serve to client
		while (true){
			cout<<"\n\n\t1.CREATE STUDENT RECORD";
			cout<<"\n\n\t2.DISPLAY STUDENTS RECORDS";
			cout<<"\n\n\t3.MODIFY STUDENT RECORD";
			cout<<"\n\n\t4.Exit" << endl;
			cin >> option;

			switch (option) {
				case 1:
					cout << "\n Enter id: ";
					cin >> id;
					send(ConnectSocket, id.c_str(), id.size(), 0);
					cout << "\n Enter name: ";
					cin >> name;
					send(ConnectSocket, name.c_str(), name.size(), 0);
					cout << "\n Enter age: ";
					cin >> age;
					send(ConnectSocket, age.c_str(), age.size(), 0);

					recv(ConnectSocket, connectedClient, 256, 0);
					cout << "\nResponse to server: "<<connectedClient;
					break;
				case 2:
					cout << "\n Enter student id: ";
					cin >> id;
					send(ConnectSocket, id.c_str(), id.size(), 0);

					recv(ConnectSocket, connectedClient, 256, 0);
					cout << "\nResponse to server: "<<connectedClient;
					break;
				case 4:
					exit(0);
				default:
					break;
			}
		}
		
		// //Nhap ten
		
		// recv(ConnectSocket,connectedClient,256,0);
	
		// cout << "\nResponse to server: "<<connectedClient;
	}

    closesocket(ConnectSocket);
    WSACleanup();
    return 0;
}

