#include "CPoint.h"
CPoint::CPoint(int _x,int _y):x(_x),y(_y){}

void CPoint::Print() {
	cout << "Point's data: "
		<< '(' << x << ',' << y << ')' << endl;
}
