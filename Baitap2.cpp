#include <iostream>
#include <fstream>
using namespace std;

int Check(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return n > 1;
}

int main() {
	ifstream FileIn;
	FileIn.open("INPUT.TXT", ios_base::in);
	if (FileIn.fail() == true ) {
		cout << " File cua ban khong ton tai !";
		return 0;
	}
	int a[100];
	int i = 0;
	int dem = 0;
	while (FileIn.eof() == false) {
		FileIn >> a[i];
		++i;
		++dem;
	}
	ofstream FileOut;
	FileOut.open("KETQUA.TXT", ios_base::out);
	FileOut << " Ket qua la : " << endl;
	for (int i = 0; i < dem - 1; i++) {
		if (Check(a[i])) {
			FileOut << a[i] << " ";
		}
	}
	FileOut.close();
	FileIn.close();
	return 0;
}