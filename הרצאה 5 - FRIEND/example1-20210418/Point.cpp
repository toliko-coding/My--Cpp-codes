#include "Point.h"
CPoint::CPoint(int _x, int _y) :x(_x), y(_y) {}

void CPoint::Print()const {
	cout << "Point's data: "
		<< '(' << x << ',' << y << ')' << endl;
}
bool CPoint::operator == (const CPoint& second)const {
	return x == second.x && y == second.y;
}
bool CPoint::operator != (const CPoint& second)const {
	return !(*this == second);//return this->x != second.x || y != second.y;
}

CPoint& CPoint::operator += (const CPoint& second) {
	x += second.x;
	y += second.y;
	return *this;
}

CPoint CPoint::operator + (const CPoint& second) const {
	CPoint temp(*this);
	temp += second;
	return temp;
}

CPoint& CPoint::operator ++() {
	x++;
	return *this;
}
CPoint CPoint::operator++(int) {
	CPoint temp(*this);
	y++;
	return temp;
}

ostream& operator << (ostream& output, const CPoint& obj) {
	//obj.Print();
	output << "Point's data: "
		<< '(' << obj.x << ',' << obj.y << ')' << endl;
	return output;// enables cout<<p1<<p2;   
}
istream& operator >> (istream& input, CPoint& obj) {
	cout << " Enter x and y :";
	input >> obj.x >> obj.y;
	return input;// enables cin>>x>>y>>z;
}