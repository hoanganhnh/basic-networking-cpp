#include <winsock2.h>
#include<bits/stdc++.h>

using namespace std;

#include "E:\owner-project\server-client\UDP\Subject-Scores\Student.h"

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

    
    char answer[BUFLEN] = {};

    // try to receive some data, this is a blocking call
    int slen = sizeof(sockaddr_in);
    // start communication
    string id, res;
    int option;
    Student st;

    while (1) {
        while (true){
            cout<<"\n 1.DISPLAY STUDENT INFORMATION";
			cout<<"\n 2.DISPLAY STUDENTS RECORDS";
			cout<<"\n 3.Exit" << endl;

            cout<< "\n Choose Option: ";
			cin >> option;

            switch (option) {
                case 1:
                    cout << "Enter student ID: ";
                    cin >> id;
                    sendto(client_socket, id.c_str(), id.size(), 0, (sockaddr*)&server, sizeof(sockaddr_in));

                    
                    recvfrom(client_socket, answer, BUFLEN, 0, (sockaddr*)&server, &slen);
                    res = answer;
                    cout << "\n" << res << endl;
                    break;
                case 2:
                    st.showAllInforStudent();
                    break;
                case 3:
                    exit(0);
                default:
                    break;
            }
        }
        cout << "\n Enter student ID: ";
        // char message[BUFLEN];
        


    }

    closesocket(client_socket);
    WSACleanup();
}