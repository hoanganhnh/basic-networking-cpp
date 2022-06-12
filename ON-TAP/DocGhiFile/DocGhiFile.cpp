#include<bits/stdc++.h>
#include<fstream>
using namespace std;

struct monhoc {
	string tenmonhoc;
	float diem;
};
typedef struct monhoc MonHoc;

struct sinhvien {
	string hoten;
	string maso;
	string namsinh;
	vector<MonHoc> ds_monhoc;
};
typedef struct sinhvien SinhVien;

void Doc_File_Thong_Tin_Sinh_Vien(ifstream &filein, SinhVien &sv){
	getline(filein, sv.hoten, ',');
	getline(filein, sv.maso, ',');
	getline(filein, sv.namsinh);
}

void Doc_File_Thong_Tin_Mon_Hoc(ifstream &filein, MonHoc &mon){
	getline(filein, mon.tenmonhoc, '-');
	filein >> mon.diem;
}

void Doc_File(ifstream &filein, vector<SinhVien> &ds_sinhvien){
	while(filein.eof() == false){
		SinhVien sv;
		Doc_File_Thong_Tin_Sinh_Vien(filein, sv);
		int n;
		filein >> n;
		string temp;
		getline(filein, temp);
		for(int i=1;i<=n;i++){
			MonHoc mon;
			Doc_File_Thong_Tin_Mon_Hoc(filein, mon);
			getline(filein, temp);
			sv.ds_monhoc.push_back(mon);
		}
		ds_sinhvien.push_back(sv);
	}
}

void Xuat_Thong_Tin_Sinh_Vien(SinhVien sv){
	cout << "\nHo ten sinh vien: " << sv.hoten;
	cout << "\nMa sinh vien: " << sv.maso;
	cout << "\nNgay sinh: " << sv.namsinh;
}

void Xuat_Thong_Tin_Mon_Hoc(MonHoc mon){
	cout << "\nTen mon hoc: " << mon.tenmonhoc;
	cout << "\nDiem: " << mon.diem;
}

void Test(vector<SinhVien> ds){
	for(int i=0;i<ds.size();i++){
		cout<< "\n\n\t\t\t SINH VIEN THU " << i+1;
		Xuat_Thong_Tin_Sinh_Vien(ds[i]);
		cout << "\n=======================DANH SACH MON HOC TUONG UNG=====================\n";
		for(int j=0;j<ds[i].ds_monhoc.size();j++){
			cout << "\n\t\tMON HOC THU " << j+1;
			Xuat_Thong_Tin_Mon_Hoc(ds[i].ds_monhoc[j]);
		}
	}
}

void Tim_Kiem_Sinh_Vien_Theo_Ho_Ten(vector<SinhVien> ds, string hoten){
	int dem = 1;
	for(int i=0;i<ds.size();i++){
		if(stricmp(ds[i].hoten.c_str(), hoten.c_str()) == 0){
			cout << "\n\n\t\t\t SINH VIEN THU " << dem++;
			Xuat_Thong_Tin_Sinh_Vien(ds[i]);
			int n = ds[i].ds_monhoc.size();
			for(int j=0;j<n;j++){
				cout << "\n\t\t MON HOC THU " << j+1;
				Xuat_Thong_Tin_Mon_Hoc(ds[i].ds_monhoc[j]);
			}
		}
	}
}

int main(){
	ifstream filein;
	filein.open("SinhVien.txt", ios_base::in);
	vector<SinhVien> ds_sinhvien;
	Doc_File(filein, ds_sinhvien);
	cout << "\nDu lieu da doc thanh cong!";
	string hoten;
	cout << "\n Nhap ho ten sinh vien can tim kiem: ";
	getline(cin, hoten);
	Tim_Kiem_Sinh_Vien_Theo_Ho_Ten(ds_sinhvien, hoten);
	filein.close();
	system("pause");
	return 0;
}
