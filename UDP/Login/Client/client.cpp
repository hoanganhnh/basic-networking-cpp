#include <winsock2.h>
#include<bits/stdc++.h>

using namespace std;

#pragma comment(lib, "ws2_32.lib")
#pragma warning(disable:4996)

#define SERVER "127.0.0.1"  // or "localhost" - ip address of UDP server
#define BUFLEN 512  // max length of answer
#define PORT 8888  // the port on which to listen for incoming data

int main() {
    system("title UDP Client");

    // initialise winsock
    WSADATA ws;
    printf("Initialising Winsock...");
    if (WSAStartup(MAKEWORD(2, 2), &ws) != 0) {
        printf("Failed. Error Code: %d", WSAGetLastError());
        return 1;
    }
    printf("Initialised.\n");

    // create socket
    sockaddr_in server;
    int client_socket;
    if ((client_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == SOCKET_ERROR) /* <<< UDP socket */{
        printf("socket() failed with error code: %d", WSAGetLastError());
        return 2;
    }

     // setup address structure
    memset((char*)&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.S_un.S_addr = inet_addr(SERVER);

    // start communication
    string username, pass;

    while (true) {
        char message[BUFLEN];
        cout << "\n Enter username: ";
		getline(cin,username);
		cout << "\n Enter password: ";
		getline(cin,pass);

		sendto(client_socket, username.c_str(), username.size(), 0, (sockaddr*)&server, sizeof(sockaddr_in));
		sendto(client_socket, pass.c_str(), pass.size(), 0, (sockaddr*)&server, sizeof(sockaddr_in));

        char answer[BUFLEN] = {};

        // try to receive some data, this is a blocking call
        int slen = sizeof(sockaddr_in);
        int answer_length;
        
        recvfrom(client_socket, answer, BUFLEN, 0, (sockaddr*)&server, &slen);
        string res = answer;
        if(res=="1") {
            cout << "Co ton tai Username va password trong CSDL" << endl;
        } else {
            cout << "Khong ton tai Username va password trong CSDL" << endl;
        }

    }

    closesocket(client_socket);
    WSACleanup();
}