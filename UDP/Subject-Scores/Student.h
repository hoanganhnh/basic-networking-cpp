#include <bits/stdc++.h>

using namespace std;

class Student {
private:
    string id;

public:
	Student(){}
	Student(string id) {
		this->id = id;
	}
	
	bool stringContain(string s1, string s2) {
        cout << "s1: "<< s1 << endl;
        cout << "s2: "<< s2 << endl;
		if (s1.find(s2) != string::npos) {
            cout << "true" << endl;
            return true;
        }
        return false;
		
	}
	string getDataStudent() {
        string path = "E:/owner-project/server-client/UDP/Subject-Scores/student.txt";
        
		fstream File;
		string s="";
        bool found=false;

        File.open(path,ios::binary|ios::in|ios::out);
        if(!File) {
            cout<<"File could not be open !! Press any Key...";
            cin.ignore();
            cin.get();
            return "Error read file !";
	    }

		while (!File.eof() && found==false) {
			getline(File, s);
			if (s.find(this->id) != string::npos) {
                cout << "s: "<< s << endl;
				found = true;
                return s;
                break;
            }
		}
        File.close();
        if(found==false) {
            return "\n\n Record Not Found !";
        }
        cin.ignore();
        cin.get();
        return s;
	}

    void showAllInforStudent() {
        string path = "E:/owner-project/server-client/UDP/Subject-Scores/student.txt";
        
		fstream File;
		string res="";

        File.open(path,ios::binary|ios::in|ios::out);
        if(!File) {
            cout<<"File could not be open !! Press any Key...";
            cin.ignore();
            cin.get();
            return;
	    }

		while (!File.eof()) {
			getline(File, res);
            cout << res << endl;
		}
        File.close();
        cin.ignore();
        cin.get();
    }
};
