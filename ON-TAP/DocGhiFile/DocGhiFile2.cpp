#include<bits/stdc++.h>
using namespace std;
#include<fstream>
#include<string>
#include<vector>
#pragma warning(disable:4996)

// khai báo c?u trúc môn h?c
struct monhoc
{
	string tenmonhoc;
	float diem;
};
typedef struct monhoc MonHoc;

// khai báo c?u trúc sinh viên
struct sinhvien
{
	string hoten;
	string maso;
	string namsinh;
	vector< MonHoc> ds_monhoc;// m?ng 1 chi?u các môn h?c c?a sinh viên
};
typedef struct sinhvien SinhVien;

// hàm d?c file thông tin c?a 1 th?ng sinh viên
void Doc_File_Thong_Tin_Sinh_Vien(ifstream &filein, SinhVien &sv)
{
	getline(filein, sv.hoten, ','); // d?c d? li?u d?n d?u ','
	getline(filein, sv.maso, ','); // d?c d? li?u d?n d?u ','
	getline(filein, sv.namsinh); // d?c d? li?u d?n d?u ','
}

// hàm d?c file thông tin c?a 1 môn h?c
void Doc_File_Thong_Tin_Mon_Hoc(ifstream &filein, MonHoc &mon)
{
	getline(filein, mon.tenmonhoc, '-'); // d?c d? li?u d?n d?u '-'
	filein >> mon.diem; // d?c di?m t? file
}

// hàm d?c thông tin sinh viên và danh sách môn h?c tuong ?ng
void Doc_File(ifstream &filein, vector< SinhVien> &ds_sinhvien)
{
	// vòng l?p l?p d?n cu?i file thì d?ng
	while (filein.eof() == false)
	{
		SinhVien sv; // khai báo ra sinh viên d? nh?n d? li?u t? file v?
		// BU?C 1: d?c thông tin c?a 1 th?ng sinh viên
		Doc_File_Thong_Tin_Sinh_Vien(filein, sv);
		// BU?C 2: d?c s? lu?ng môn h?c mà sinh viên dã h?c
		int n; // s? lu?ng môn h?c
		filein >> n; // d?c d? li?u mà s? lu?ng môn h?c t? file

		// có cái này d? d?c kí t? '\n' c?a cái dòng bên trên
		string temp;
		getline(filein, temp);
		// BU?C 3: d?c danh sách các môn h?c mà th?ng sinh viên dã h?c
		for (int i = 1; i <= n; i++)
		{
			MonHoc mon; // khai báo MonHoc d? ch?a d? li?u d?c t? file v?
			Doc_File_Thong_Tin_Mon_Hoc(filein, mon);
			// có cái này d? d?c kí t? '\n' c?a cái dòng bên trên
			getline(filein, temp);
			sv.ds_monhoc.push_back(mon); // thêm 1 môn h?c vào cu?i m?ng vector danh sách môn h?c c?a th?ng sinh viên tuong ?ng
		}
		
		// BU?C 4: Thêm thông tin sinh viên vào m?ng 1 chi?u vector sinh viên - danh sách sinh viên
		ds_sinhvien.push_back(sv); // thêm sinh viên vào cu?i m?ng
	}
}

// hàm xu?t thông tin c?a 1 th?ng sinh viên
void Xuat_Thong_Tin_Sinh_Vien(SinhVien sv)
{
	cout << "\nHo ten sinh vien: " << sv.hoten;
	cout << "\nMa so sinh vien: " << sv.maso;
	cout << "\nNgay thang nam sinh: " <<  sv.namsinh;
}

// hàm xu?t thông tin c?a 1 môn h?c
void Xuat_Thong_Tin_Mon_Hoc(MonHoc mon)
{
	cout << "\nTen mon hoc: " << mon.tenmonhoc;
	cout << "\nDiem: " << mon.diem;
}
// hàm test xu?t d? li?u sinh viên
void Test(vector<SinhVien> ds)
{
	for (int i = 0; i < ds.size(); i++)
	{
		cout << "\n\n\t\t\t SINH VIEN THU " << i + 1;
		// g?i hàm xu?t thông tin c?a sinh viên
		Xuat_Thong_Tin_Sinh_Vien(ds[i]);
		cout << "\n=========== DANH SACH MON HOC TUONG UNG ===========\n";
		// xu?t ra danh sách các môn h?c c?a th?ng sinh viên th? i tuong ?ng
		for (int j = 0; j < ds[i].ds_monhoc.size(); j++)
		{
			cout << "\n\t\tMON HOC THU " << j + 1;
			Xuat_Thong_Tin_Mon_Hoc(ds[i].ds_monhoc[j]);
		}
	}
}

// câu 2: hàm xu?t t?t c? thông tin c?a sinh viên có tên trùng
void Tim_Kiem_Sinh_Vien_Theo_Ho_Ten(vector<SinhVien> ds, string hoten)
{
	int dem = 1;
	for (int i = 0; i < ds.size(); i++)
	{
		// dùng hàm so sánh 2 chu?i không phân bi?t kí t? hoa thu?ng
		if (stricmp(ds[i].hoten.c_str(), hoten.c_str()) == 0)
		{
			cout << "\n\n\t\t\t SINH VIEN THU " << dem++;
			// BU?C 1: xu?t thông tin c?a sinh viên
			Xuat_Thong_Tin_Sinh_Vien(ds[i]);
			// BU?C 2: xu?t ra danh sách các môn h?c c?a sinh viên tuong ?ng
			int n = ds[i].ds_monhoc.size(); // s? lu?ng các môn h?c
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
	// khai báo danh sách sinh viên
	vector< SinhVien> ds_sinhvien;
	// câu 1: d?c t?t c? d? li?u t? file SINHVIEN.TXT
	Doc_File(filein, ds_sinhvien);
	cout << "\nDu lieu da doc thanh cong !";

	//// xu?t d? li?u ra màn hình d? ki?m tra
	//Test(ds_sinhvien);
	string hoten;
	cout << "\n Nhap ho ten sinh vien can tim kiem: ";
	getline(cin, hoten);
	Tim_Kiem_Sinh_Vien_Theo_Ho_Ten(ds_sinhvien, hoten);

	filein.close(); // dóng file SINHVIEN.TXT
	system("pause");
	return 0;
}
