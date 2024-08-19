#include <iostream>
#include <fstream>
#include <vector>
#include <string>
//#pragma 
using namespace std;
struct MH {
	string tenmh;
	float diem;
};
struct SV {
	string ten;
	string masv;
	string ngaysinh;
	vector <MH> ds_monhoc;
};

void Thong_tin_1_sinh_vien(ifstream &filein, SV& sv){
	getline(filein, sv.ten, ',');
	getline(filein, sv.masv, ',');
	getline(filein, sv.ngaysinh);
}

void Thong_tin_1_mon_hoc(ifstream& filein, MH& mh) {
	getline(filein, mh.tenmh, '-');
	filein >> mh.diem;
}

void Doc_file(ifstream& filein, vector <SV>& ds_sinhvien) {
	while (true) {
		SV sv;
		Thong_tin_1_sinh_vien(filein, sv);
		if (filein.fail() == true) {
			break;
		}
		int n;
		filein >> n;
		//string tmp;
		//getline(filein, tmp);
		filein.ignore();
		for (int i = 0; i < n; i++) {
			MH mh;
			Thong_tin_1_mon_hoc(filein, mh);
			//getline(filein, tmp);
			filein.ignore();
			sv.ds_monhoc.push_back(mh);
			if (filein.fail() == true) {
				break;
			}
		}
		ds_sinhvien.push_back(sv);
	}
}

void Xuat_1_sinh_vien(SV sv) {
	cout << " Ho va ten sinh vien la : " << sv.ten << endl;
	cout << " Ma so sinh vien la : " << sv.masv << endl;
	cout << " Ngay sinh cua sinh vien la : " << sv.ngaysinh << endl;
}

void Xuat_1_mon_hoc(MH mh) {
	cout << " Ten mon hoc la : " << mh.tenmh << "-" << mh.diem << endl;
}

void  Text(vector <SV> ds_sinhvien) {
	int n = ds_sinhvien.size();
	cout << "\t\t ============= THONG TIN  SINH VIEN LA ========== \n";
	for (int i = 0; i < n; i++) {
		cout << "\n\t\t======================= \n";
		Xuat_1_sinh_vien(ds_sinhvien[i]);
		int m = ds_sinhvien[i].ds_monhoc.size();
		for (int j = 0; j < m; j++) {
			Xuat_1_mon_hoc(ds_sinhvien[i].ds_monhoc[j]);
		}
	}
}

// Cau 2:
void Tim_kiem_sinh_vien_theo_ho_ten(vector <SV> ds_sinhvien, string hoten) {
	int n = ds_sinhvien.size();
	for (int i = 0; i < n; i++) {
		if (_stricmp(ds_sinhvien[i].ten.c_str(), hoten.c_str()) == 0) {
			cout << " Yes !";
			cout << "\n\t\t SINH VIEN THU " << i + 1 << endl;
			// Buoc 1: xuat thong tin cua sinh vien;
			Xuat_1_sinh_vien(ds_sinhvien[i]);
			// Buoc 2 : xuat ra danh sach mon hoc sinh vine 
			int k = ds_sinhvien[i].ds_monhoc.size();
			for (int j = 0; j < k; j++) {
				cout << " \n \t\t MON HOC THU " << j + 1 << endl;
				Xuat_1_mon_hoc(ds_sinhvien[i].ds_monhoc[j]);
			}
		}
	}
}
int main() {
	ifstream filein;
	filein.open("INPUT.TXT", ios_base::in);
	vector <SV> ds_sinhvien;
	if (filein.fail() == true) {
		cout << " File khong ton tai !" << endl;
		return 0;
	}
	Doc_file(filein, ds_sinhvien);
	cout << " Du lieu da doc thanh cong !" << endl;
	Text(ds_sinhvien);
	string hoten;
	cout << "\n Nhap ho ten sinh vien can tim kiem :  ";
	getline(cin, hoten);
	Tim_kiem_sinh_vien_theo_ho_ten(ds_sinhvien, hoten);
	filein.close();
	return 0;
}