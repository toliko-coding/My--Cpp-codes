#include "CPoint.h"
CPoint::CPoint(int _x,int _y):x(_x),y(_y){}
CPoint::~CPoint() {
	cout << "................................................................" << endl;
	cout << "I'm dtor , this is the data of the CPoint destroyed object :\n";
	Print();
	cout << "................................................................" << endl;
}

void CPoint::Print() {
	cout << "Point's data: "
		<< '(' << x << ',' << y << ')' << endl;
}