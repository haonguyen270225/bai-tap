#include "Diem.h"
void Diem :: dichuyen( double dx , double dy ){
	this -> x += dx;
	this -> y += dy;
}
istream& operator >>( istream &is , Diem &u){
	is >> u.x  >> u.y;
	return is;
}
ostream& operator <<(ostream &os , Diem &u){
	os << "(" << u.x  << "," << u.y << ")" << endl;
	return os;
}
Diem operator +( Diem u , Diem v){
	Diem res;
	res.x = u.x + v.x;
	res.y = u.y + v.y;
	return res;
}
double Diem :: khoancach( Diem u ){
	return sqrt(pow(u.x - this -> x , 2) + pow(u.y - this -> y , 2));
}
