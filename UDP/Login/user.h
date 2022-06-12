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
	bool checkExistInFile() {
        string path = "E:/owner-project/server-client/UDP/Login/userInfor.txt";
        
		ifstream readFile(path, ios::in);
		string s;
		string templete = getName() + ' ' + getPassword();

		while (!readFile.eof()) {
			getline(readFile, s);
			if (compareString(templete, s))
				return true;
		}
		return false;
	}
};
