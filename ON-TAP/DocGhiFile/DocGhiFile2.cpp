#include<bits/stdc++.h>
using namespace std;
#include<fstream>
#include<string>
#include<vector>
#pragma warning(disable:4996)

// khai b�o c?u tr�c m�n h?c
struct monhoc
{
	string tenmonhoc;
	float diem;
};
typedef struct monhoc MonHoc;

// khai b�o c?u tr�c sinh vi�n
struct sinhvien
{
	string hoten;
	string maso;
	string namsinh;
	vector< MonHoc> ds_monhoc;// m?ng 1 chi?u c�c m�n h?c c?a sinh vi�n
};
typedef struct sinhvien SinhVien;

// h�m d?c file th�ng tin c?a 1 th?ng sinh vi�n
void Doc_File_Thong_Tin_Sinh_Vien(ifstream &filein, SinhVien &sv)
{
	getline(filein, sv.hoten, ','); // d?c d? li?u d?n d?u ','
	getline(filein, sv.maso, ','); // d?c d? li?u d?n d?u ','
	getline(filein, sv.namsinh); // d?c d? li?u d?n d?u ','
}

// h�m d?c file th�ng tin c?a 1 m�n h?c
void Doc_File_Thong_Tin_Mon_Hoc(ifstream &filein, MonHoc &mon)
{
	getline(filein, mon.tenmonhoc, '-'); // d?c d? li?u d?n d?u '-'
	filein >> mon.diem; // d?c di?m t? file
}

// h�m d?c th�ng tin sinh vi�n v� danh s�ch m�n h?c tuong ?ng
void Doc_File(ifstream &filein, vector< SinhVien> &ds_sinhvien)
{
	// v�ng l?p l?p d?n cu?i file th� d?ng
	while (filein.eof() == false)
	{
		SinhVien sv; // khai b�o ra sinh vi�n d? nh?n d? li?u t? file v?
		// BU?C 1: d?c th�ng tin c?a 1 th?ng sinh vi�n
		Doc_File_Thong_Tin_Sinh_Vien(filein, sv);
		// BU?C 2: d?c s? lu?ng m�n h?c m� sinh vi�n d� h?c
		int n; // s? lu?ng m�n h?c
		filein >> n; // d?c d? li?u m� s? lu?ng m�n h?c t? file

		// c� c�i n�y d? d?c k� t? '\n' c?a c�i d�ng b�n tr�n
		string temp;
		getline(filein, temp);
		// BU?C 3: d?c danh s�ch c�c m�n h?c m� th?ng sinh vi�n d� h?c
		for (int i = 1; i <= n; i++)
		{
			MonHoc mon; // khai b�o MonHoc d? ch?a d? li?u d?c t? file v?
			Doc_File_Thong_Tin_Mon_Hoc(filein, mon);
			// c� c�i n�y d? d?c k� t? '\n' c?a c�i d�ng b�n tr�n
			getline(filein, temp);
			sv.ds_monhoc.push_back(mon); // th�m 1 m�n h?c v�o cu?i m?ng vector danh s�ch m�n h?c c?a th?ng sinh vi�n tuong ?ng
		}
		
		// BU?C 4: Th�m th�ng tin sinh vi�n v�o m?ng 1 chi?u vector sinh vi�n - danh s�ch sinh vi�n
		ds_sinhvien.push_back(sv); // th�m sinh vi�n v�o cu?i m?ng
	}
}

// h�m xu?t th�ng tin c?a 1 th?ng sinh vi�n
void Xuat_Thong_Tin_Sinh_Vien(SinhVien sv)
{
	cout << "\nHo ten sinh vien: " << sv.hoten;
	cout << "\nMa so sinh vien: " << sv.maso;
	cout << "\nNgay thang nam sinh: " <<  sv.namsinh;
}

// h�m xu?t th�ng tin c?a 1 m�n h?c
void Xuat_Thong_Tin_Mon_Hoc(MonHoc mon)
{
	cout << "\nTen mon hoc: " << mon.tenmonhoc;
	cout << "\nDiem: " << mon.diem;
}
// h�m test xu?t d? li?u sinh vi�n
void Test(vector<SinhVien> ds)
{
	for (int i = 0; i < ds.size(); i++)
	{
		cout << "\n\n\t\t\t SINH VIEN THU " << i + 1;
		// g?i h�m xu?t th�ng tin c?a sinh vi�n
		Xuat_Thong_Tin_Sinh_Vien(ds[i]);
		cout << "\n=========== DANH SACH MON HOC TUONG UNG ===========\n";
		// xu?t ra danh s�ch c�c m�n h?c c?a th?ng sinh vi�n th? i tuong ?ng
		for (int j = 0; j < ds[i].ds_monhoc.size(); j++)
		{
			cout << "\n\t\tMON HOC THU " << j + 1;
			Xuat_Thong_Tin_Mon_Hoc(ds[i].ds_monhoc[j]);
		}
	}
}

// c�u 2: h�m xu?t t?t c? th�ng tin c?a sinh vi�n c� t�n tr�ng
void Tim_Kiem_Sinh_Vien_Theo_Ho_Ten(vector<SinhVien> ds, string hoten)
{
	int dem = 1;
	for (int i = 0; i < ds.size(); i++)
	{
		// d�ng h�m so s�nh 2 chu?i kh�ng ph�n bi?t k� t? hoa thu?ng
		if (stricmp(ds[i].hoten.c_str(), hoten.c_str()) == 0)
		{
			cout << "\n\n\t\t\t SINH VIEN THU " << dem++;
			// BU?C 1: xu?t th�ng tin c?a sinh vi�n
			Xuat_Thong_Tin_Sinh_Vien(ds[i]);
			// BU?C 2: xu?t ra danh s�ch c�c m�n h?c c?a sinh vi�n tuong ?ng
			int n = ds[i].ds_monhoc.size(); // s? lu?ng c�c m�n h?c
			for (int j = 0; j < n; j++)
			{
				cout << "\n\t\t MON HOC THU " << j + 1;
				Xuat_Thong_Tin_Mon_Hoc(ds[i].ds_monhoc[j]);
			}

		}
	}
}

int main()
{
	ifstream filein;
	filein.open("SinhVien.txt", ios_base::in); // m? file SINHVIEN.TXT ra d?c d? li?u
	// khai b�o danh s�ch sinh vi�n
	vector< SinhVien> ds_sinhvien;
	// c�u 1: d?c t?t c? d? li?u t? file SINHVIEN.TXT
	Doc_File(filein, ds_sinhvien);
	cout << "\nDu lieu da doc thanh cong !";

	//// xu?t d? li?u ra m�n h�nh d? ki?m tra
	//Test(ds_sinhvien);
	string hoten;
	cout << "\n Nhap ho ten sinh vien can tim kiem: ";
	getline(cin, hoten);
	Tim_Kiem_Sinh_Vien_Theo_Ho_Ten(ds_sinhvien, hoten);

	filein.close(); // d�ng file SINHVIEN.TXT
	system("pause");
	return 0;
}
