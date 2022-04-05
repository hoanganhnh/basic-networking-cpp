#include <winsock2.h>
#include<bits/stdc++.h>

using namespace std;

#pragma comment(lib, "ws2_32.lib")
#pragma warning(disable:4996)

#define SERVER "127.0.0.1"  // or "localhost" - ip address of UDP server
#define BUFLEN 512  // max length of answer
#define PORT 8081  // the port on which to listen for incoming data

const char* IP = "10.10.17.20";

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
    // server.sin_addr.S_un.S_addr = inet_addr(SERVER);
    server.sin_addr.S_un.S_addr = inet_addr(IP);

    // start communication
    string cd, cr;

    while (true) {
        char message[BUFLEN];
        cout << "\n Enter chieu dai: ";
		getline(cin,cd);
		cout << "\n Enter chieu rong: ";
		getline(cin,cr);

		sendto(client_socket, cd.c_str(), cd.size(), 0, (sockaddr*)&server, sizeof(sockaddr_in));
		sendto(client_socket, cr.c_str(), cr.size(), 0, (sockaddr*)&server, sizeof(sockaddr_in));

        char answer[BUFLEN] = {};

        // try to receive some data, this is a blocking call
        int slen = sizeof(sockaddr_in);
        int answer_length;
        
        recvfrom(client_socket, answer, BUFLEN, 0, (sockaddr*)&server, &slen);
        string res = answer;
        
        cout << "\n Dien tich tam giac bang: "<< res << endl;

    }

    closesocket(client_socket);
    WSACleanup();
}