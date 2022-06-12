#include<iostream>
#include<fstream>
#include<iomanip>
 
using namespace std;

const string pathData = "C:\\Users\\Dell Inc\\Downloads\\student-info-demo\\data\\data.txt";

void clear() {
    ofstream file(pathData);
    file<<"";
}
class Student {
    public:
        string id;
        string name;

    void write_data(string ID, string NAME) {
        clear();
        string data = "ID: " + ID+"\n"+ "Name: " +NAME;
        ofstream file1;
        file1.open(pathData, ios::app);
        file1 << data;
        file1.close();
    }

    void output() {
        string line;
        ifstream file;
        file.open(pathData);
        file.seekg(0);
        if (file.is_open()){
            while (getline(file,line)){
                cout << line << '\n';
            }
            file.close();
        }
    }
};
