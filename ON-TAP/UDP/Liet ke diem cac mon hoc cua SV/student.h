#include<bits/stdc++.h>
using namespace std;

class Student {
	private:
		string Name, Id;
		float Java, ToanCC, LTM, CSDL;
	public:
		void setName(string vName){
			Name = vName;
		}
		void setId(string vId){
			Id = vId;
		}
		string getId(){
			return Id;
		}
		float getJava(){
			return Java;
		}
		float getToanCC(){
			return ToanCC;
		}
		float getLTM(){
			return LTM;
		}
		float getCSDL(){
			return CSDL;
		}
		void Display();
		
		string Check(){
			ifstream newFile;
			string str, kq;
			string result = "0";
			string addstr = Id;
			newFile.open("DSSV.txt", ios::in);
			int pos = 0;
			while(!newFile.eof()){
				getline(newFile, str, '#');
				getline(newFile, Name, '#');
				newFile >> Java;
				newFile.ignore();
				newFile >> ToanCC;
				newFile.ignore();
				newFile >> LTM;
				newFile.ignore();
				newFile >> CSDL;
				newFile.ignore();
				pos = str.find(addstr);
				if(pos >= 0){
					kq = str;
				}
			}
			newFile.close();
			return kq;
		}
};

void Student::Display(){
	string kq = Check();
	ifstream Filein;
	Filein.open("DSSV.txt", ios::in);
	while(!Filein.eof()){
			getline(Filein, Id, '#');
				getline(Filein, Name, '#');
				Filein >> Java;
				Filein.ignore();
				Filein >> ToanCC;
				Filein.ignore();
				Filein >> LTM;
				Filein.ignore();
				Filein >> CSDL;
				Filein.ignore();
				if(kq == Id){
					cout << "\nTen sinh vien la: " << Name;
					cout << "\nThong tin diem Java: " << Java;
					cout << "\nThong tin diem Toan Cao Cap: " << ToanCC;
					cout << "\nThong tin diem Lap Trinh Mang: " << LTM;
					cout << "\nThong tin diem CSDL: " << CSDL;
				}
	}
	Filein.close();
}
