#ifndef Diem_h
#define Diem_h
#include <iostream>
#include <math.h>
using namespace std;
class Diem{
	private:
		double x , y;
	public:
		Diem( double x = 0 , double y = 0 ) : x(x) , y(y){};
		void dichuyen( double dx , double dy );
		friend istream& operator >>( istream &is , Diem &u);
		friend ostream& operator <<(ostream &os , Diem &u);
		friend Diem operator +( Diem u , Diem v);
		double khoancach( Diem u );
};
#endif
