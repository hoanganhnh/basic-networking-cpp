#include<iostream>
#include<fstream>
#include<iomanip>
 
using namespace std;

const string pathData = "E:\\owner-project\\server-client\\TCP\\student-info\\data\\student.txt";

class Student {
    int id;
    string name;
    string age;

    public:
        void getdata() {
            cout<<"\nEnter The ID number of the student: ";
            cin >> id;
            cout<<"\nEnter student's Name: ";
            cin >> name;
            cout<<"\nEnter student's age : ";
            cin >> age;
        }
        void showdata() {
            cout<<"\n\n\tID Number: "<< this->id;
            cout<<"\n\n\tName: "<< this->name;
            cout<<"\n\n\tAge: "<< this->age;
        }

        int getIDNum() {
            return id;
        }

        void display_all() {
        	Student st;
        	ifstream inFile;
        	inFile.open(pathData,ios::binary);
        	if(!inFile) {
        		cout<<"File could not be open !! Press any Key...";
        		cin.ignore();
        		cin.get();
        		return;
        	}
            cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
            while(inFile.read(reinterpret_cast<char *> (&st), sizeof(Student))) {
                st.showdata();
                cout<<"\n\n====================================\n";
            }
            inFile.close();
            cin.ignore();
            cin.get();
        }
    
        void write_student() {
            Student st;
            ofstream outFile;
            outFile.open(pathData,ios::binary|ios::app);
            st.getdata();
            outFile.write(reinterpret_cast<char *> (&st), sizeof(Student));
            outFile.close();
            cout<<"\n\nStudent record Has Been Created ";
            cin.ignore();
            cin.get();
        }

        void changeName(string username) {
            this->name = username;
        }

        void modify_student(string nameChange) {
            bool found=false;
            Student st;
            fstream File;
            File.open(pathData, ios::binary|ios::in|ios::out);
            if(!File) {
                cout<<"File could not be open !! Press any Key...";
                cin.ignore();
                cin.get();
                return;
            }
            while(!File.eof() && found==false) {

        		File.read(reinterpret_cast<char *> (&st), sizeof(Student));
        		// if(st.getIDNum() == numId) {
        			// st.showdata();
        			// st.getdata();
                    changeName(nameChange);
                    int pos=(-1)*static_cast<int>(sizeof(st));
                    File.seekp(pos,ios::cur);
                    File.write(reinterpret_cast<char *> (&st), sizeof(Student));
                    cout<<"\n\n\t Record Updated";
                    found=true;
        		// }
        	}
            File.close();
            if(found==false) {
                cout<<"\n\n Record Not Found ";
            }
            cin.ignore();
            cin.get();
        }
};

// void Student::showdata() const {
// 	cout<<"\nID Number: "<<id;
// 	cout<<"\nName: "<<name;
// 	cout<<"\Age: "<<age;
	// cout<<"\njavascript: "<<javascript;
	// cout<<"\nMathematics: "<<mathematics;
	// cout<<"\nEnglish: "<<english;
	// cout<<"\nComputer Science: "<<computer;
	// cout<<"\nPercentage: "<<per;
	// cout<<"\nLetter Grade: "<<grade;
// }

// void Student::show_tabular() const {
// 	cout<<idnum<<setw(6)<<" "<<name<<setw(10)<<java<<setw(4)<<javascript<<setw(4)<<mathematics<<setw(4)
// 		<<english<<setw(4)<<computer<<setw(8)<<per<<setw(6)<<grade<<endl;
// }

// int Student::getIDNum() const {
// 	return idnum;
// }

// void write_student() {
// 	Student st;
// 	ofstream outFile;
// 	outFile.open(pathData,ios::binary|ios::app);
// 	st.getdata();
// 	outFile.write(reinterpret_cast<char *> (&st), sizeof(Student));
// 	outFile.close();
//     cout<<"\n\nStudent record Has Been Created ";
// 	cin.ignore();
// 	cin.get();
// }

// void display_all() {
// 	Student st;
// 	ifstream inFile;
// 	inFile.open(pathData,ios::binary);
// 	if(!inFile) {
// 		cout<<"File could not be open !! Press any Key...";
// 		cin.ignore();
// 		cin.get();
// 		return;
// 	}
// 	cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
// 	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(Student))) {
// 		st.showdata();
// 		cout<<"\n\n====================================\n";
// 	}
// 	inFile.close();
// 	cin.ignore();
// 	cin.get();
// }

// void display_sp(int n) {
// 	Student st;
// 	ifstream inFile;
// 	inFile.open(pathData,ios::binary);
// 	if(!inFile) {
// 		cout<<"File could not be open !! Press any Key...";
// 		cin.ignore();
// 		cin.get();
// 		return;
// 	}
// 	bool flag=false;
// 	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(Student))) {
// 		if(st.getIDNum()==n) {
// 	  		 st.showdata();
// 			 flag=true;
// 		}
// 	}
// 	inFile.close();
// 	if(flag==false) {
// 		cout<<"\n\nrecord not exist";
//     }
// 	cin.ignore();
// 	cin.get();
// }

// void modify_student(int n) {
// 	bool found=false;
// 	Student st;
// 	fstream File;
// 	File.open(pathData,ios::binary|ios::in|ios::out);
// 	if(!File) {
// 		cout<<"File could not be open !! Press any Key...";
// 		cin.ignore();
// 		cin.get();
// 		return;
// 	}
//     while(!File.eof() && found==false) {
 
// 		File.read(reinterpret_cast<char *> (&st), sizeof(Student));
// 		if(st.getIDNum()==n) {
// 			st.showdata();
// 			cout<<"\n\nPlease Enter The New Details of student"<<endl;
// 			st.getdata();
//             int pos=(-1)*static_cast<int>(sizeof(st));
//             File.seekp(pos,ios::cur);
//             File.write(reinterpret_cast<char *> (&st), sizeof(Student));
//             cout<<"\n\n\t Record Updated";
//             found=true;
// 		}
// 	}
// 	File.close();
// 	if(found==false) {
// 		cout<<"\n\n Record Not Found ";
//     }
// 	cin.ignore();
// 	cin.get();
// }

// void start() {

// 	int option;
// 	int num;
// 	cout.setf(ios::fixed|ios::showpoint);
// 	cout << setprecision(2); 
// 	do {
//         system("cls");
//         cout<<"\t---------------------------";
//         cout<<"\n\n\t1.CREATE STUDENT RECORD";
//         cout<<"\n\n\t2.DISPLAY ALL STUDENTS RECORDS";
//         cout<<"\n\n\t3.SEARCH STUDENT RECORD ";
//         cout<<"\n\n\t4.MODIFY STUDENT RECORD";
//         cout<<"\n\n\t5.EXIT";
//         cout<<"\n\n\t---------------------------";
//         cout<<"\n\n\tPlease Enter Your Choice (1-5): ";
//         cin >> option;
//         system("cls");
//         switch(option) {
//             case 1:	
//                 // write_student();
//                 break;
//             case 2:	
//                 display_all(); 
//                 break;
//             case 3:	
//                 cout<<"\n\n\tPlease Enter Student's ID number: "; 
//                 cin>>num;
//                 display_sp(num); 
//                 break;
//             case 4:	
//                 cout<<"\n\n\tPlease Enter Student's ID number: "; 
//                 cin>>num;
//                 // modify_student(num);
//                 break;
//             case 5:	exit(0);;
//             default:	
//                 cout<<"\a"; 
                
//         }
// 	} while(option != 5);
// }
