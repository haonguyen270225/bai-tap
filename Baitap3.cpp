#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

void Doc_file(int a[], int &n, ifstream& filein) {
	while (filein.eof() == false) {
		filein >> a[n];
		++n;
	}
}

void Xuat_mang(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}

bool Amstrong(int n) {
	if (n >= 0 && n <= 9) {
		return true;
	}
	int k = 0;
	int tam = n;
	while (n) {
		n /= 10;
		++k;
	}
	int tong = 0;
	n = tam;
	while (n) {
		tong = tong +  pow(n % 10, k);
		n /= 10;
	}
	if (tong == tam) {
		return true;
	}
	else {
		return false;
	}
}




void Ghi_file(int a[], int n, ofstream &fileout) {
	fileout << " Ket qua bai tap 3 : \n";
	for (int i = 0; i < n; i++) {
		if (Amstrong(a[i])) {
			fileout << a[i] << " ";
		}
	}
}



int main() {
	ifstream filein;
	filein.open("INPUT.TXT", ios_base::in);
	if (filein.fail() == true) { // Kiem tra File co ton tai !
		cout << " File  cua ban khong ton tai ! \n";
	}
	int n = 0;
	int a[100];
	Doc_file(a, n, filein);
	Xuat_mang(a, n);
	ofstream fileout;
	fileout.open("AMSTRONG.TXT", ios_base::out);
	Ghi_file(a, n, fileout );
	fileout.close();
	filein.close();
	return 0;
}