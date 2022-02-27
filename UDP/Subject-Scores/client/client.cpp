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
    string option;

    while (true) {
        cout << "\n 1. Mon tu nhien ";
        cout << "\n 2. Mon xa hoi ";
        cout << "\n 3. Thoat ";
        char message[BUFLEN];
        
        cout << "\n Enter option: ";
		getline(cin, option);

		sendto(client_socket, option.c_str(), option.size(), 0, (sockaddr*)&server, sizeof(sockaddr_in));

        char answer[BUFLEN] = {};

        // try to receive some data, this is a blocking call
        int slen = sizeof(sockaddr_in);
        
        recvfrom(client_socket, answer, BUFLEN, 0, (sockaddr*)&server, &slen);
        string res = answer;
        if (res == "exits") {
            break;
        }
        cout << "\n" << res << endl;

    }

    closesocket(client_socket);
    WSACleanup();
}