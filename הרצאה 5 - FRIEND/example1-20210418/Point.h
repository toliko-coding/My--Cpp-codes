#pragma once
#include <iostream>
using namespace std;

class CPoint {
	int x, y;
public:
	/* Gifts :
	CPoint(){}
	~CPoint(){}
	CPoint(const CPoint& other):x(other.x),y(other.y){}
	CPoint& operator= (const CPoint& other){
		x=other.x;
		y=other.y;
		return *this;
	} v=z=y;
	*/
	CPoint(int = 0, int = 0);
	void Print()const;
	//Relational  operators : == != > < >= <=
	bool operator == (const CPoint&)const;// bool operator Equal (const CPoint&)const;
	bool operator != (const CPoint&)const;

	//Integrated :+= -= *= /=
	CPoint& operator+= (const CPoint&); //cout<<(x+=y);
	//Arithmetic : + - * / %
	CPoint operator + (const CPoint&) const;// z=x+y; z.operator=(x.operator+(y));

	//prefix and postfix 
	CPoint& operator ++();// prefix ++i
	CPoint operator ++(int); // posfix i++

	//input / output
	friend ostream& operator << (ostream&, const CPoint&);
	friend istream& operator >> (istream&,  CPoint&);
};

