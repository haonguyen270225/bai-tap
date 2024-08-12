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
	int n;
	int a[100];
	FileIn >> n;
	for (int i = 0; i < n; i++) {
		FileIn >> a[i];
	}
	if (FileIn.fail() == true) {
		cout << " File cua ban khong ton tai ! \n";
	}
	else {
		for (int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
	}
	FileIn.close();
	ofstream FileOut;
	FileOut.open("KETQUA.TXT", ios_base::out);
	for (int i = 0; i < n; i++) {
		if (Check(a[i])) {
			FileOut << a[i] << " ";
		}
	}
	FileOut.close();
	return 0;
}