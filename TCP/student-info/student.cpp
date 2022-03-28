#include<iostream>
#include<fstream>
#include<iomanip>
 
using namespace std;

const string pathData = "E:\\owner-project\\server-client\\TCP\\student-info\\data\\student.txt";

void clear() {
    ofstream file(pathData);
    file<<"";
}
class Student {
    public:
        int id;
        string name;
        int age;

    void write_data(int ID, string NAME, int AGE) {
        clear();
        Student st;
        st.id = ID;
        st.name = NAME;
        st.age = AGE;

        ofstream file1;
        file1.open(pathData, ios::app);
        file1.write((char*)&st,sizeof(st));
        file1.close();
    }

    void output() {
        Student st;
        ifstream file;
        file.open(pathData,ios::in);
        file.seekg(0);
        file.read((char*)&st,sizeof(st));
        cout << "\nID :" << st.id;
        printf("\nName :%s", st.name);
        cout << "\n Age :" << st.age;
        file.close();
    }

    void modify(int idSt, string nameSt, int ageSt) {
        clear();
        Student st;
        st.id = idSt;
        st.name = nameSt;
        st.age = ageSt;
        ofstream file1;
        file1.open(pathData, ios::app);
        file1.write((char*)&st,sizeof(st));
        file1.close();
    }
};
