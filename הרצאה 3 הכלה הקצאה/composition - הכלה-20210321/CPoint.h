#pragma once
#include <iostream>
using namespace std;
class CPoint {
	int x, y;
public:
	CPoint(int = 0, int = 0); // ? Ctor
	~CPoint(); // dtor
	void Print();
	int getX() { return x;	}
	int getY() { return y; }
};

