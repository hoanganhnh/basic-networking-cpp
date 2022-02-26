#include <winsock2.h>
#include <bits/stdc++.h>

// #include "user.h"

using namespace std;

#pragma comment(lib,"ws2_32.lib") // Winsock Library
#pragma warning(disable:4996)

#define BUFLEN 512
#define PORT 8888

#include <bits/stdc++.h>

using namespace std;
class UserInfor {
private:
	string name, password;

public:
	UserInfor(){}
	UserInfor(string name, string password) {
		this->name = name;
		this->password = password;
	}
	void setName(string name) {
		this->name = name;
	}
	void setPassword(string pass) {
		this->password = pass;
	}
	string getName() {
		return name;
	}
	string getPassword() {
		return password;
	}

	bool compareString(string s1, string s2) {
		if (s1.size() != s2.size())
			return false;
		for (int i = 0; i < s1.size(); i++)
			if (tolower(s1[i]) != tolower(s2[i]))
				return false;
		return true;
	}
    string getData() {
        string path = "./userInfor.txt";
        fstream my_data;
        my_data.open(path, ios::in);
		string templete;

        if (my_data.is_open()) {
            getline(my_data, templete);
        }
        return templete;

    }
	bool checkExistInFile() {
        string dataDefault = getName() + ' ' + getPassword();
        cout << getData() << endl;
		return getData() == dataDefault;
	}
};


int main() {
    system("title UDP Server");

    sockaddr_in server, client;

    // initialise winsock
    WSADATA wsa;
    printf("Initialising Winsock...");
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        printf("Failed. Error Code: %d", WSAGetLastError());
        exit(0);
    }
    printf("Initialised.\n");

    // create a socket
    SOCKET server_socket;
    if ((server_socket = socket(AF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET) {
        printf("Could not create socket: %d", WSAGetLastError());
    }
    printf("Socket created.\n");

    // prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // bind
    if (bind(server_socket, (sockaddr*)&server, sizeof(server)) == SOCKET_ERROR) {
        printf("Bind failed with error code: %d", WSAGetLastError());
        exit(EXIT_FAILURE);
    }
    puts("Bind done.");

    string username = "";
	string pass = "";
    while (true) {
        printf("Waiting for data...");
        fflush(stdout);
        char message[BUFLEN] = {};


        int message_len;
        int slen = sizeof(sockaddr_in);


		message_len = recvfrom(server_socket, message, BUFLEN, 0, (sockaddr*)&client, &slen);
		username = message;
		memset(message, 0, sizeof(message));
		message_len = recvfrom(server_socket, message, BUFLEN, 0, (sockaddr*)&client, &slen);
		pass = message;

		UserInfor usI(username, pass);
		
		int res = usI.checkExistInFile();
		stringstream ss;
		ss << res;
		string temp;
		ss >> temp;
		
	 	
        // print details of the client/peer and the data received
        printf("Received packet from %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
        cout << "Xin chao " << usI.getName() << " - " << usI.getPassword() << endl;

        sendto(server_socket, temp.c_str(), temp.size(), 0, (sockaddr*)&client, sizeof(sockaddr_in));

    }

    closesocket(server_socket);
    WSACleanup();
}