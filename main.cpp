#include "Diem.h"
int main(){
	Diem a;
	cin >> a;
	cout << a;
	Diem b;
	cin >> b;
	cout << b;
	cout << a.khoancach(b) << endl;
	a.dichuyen(2 , 3 );
	cout << a;
	Diem c =  a+b;
	cout << c;
	return 0;
}
