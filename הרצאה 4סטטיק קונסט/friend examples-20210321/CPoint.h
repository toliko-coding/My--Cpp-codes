#pragma once
#include <iostream>
using namespace std;

class CLine; // predeclaration
class CPoint {
	int x, y;
public:
	
	CPoint(int = 0, int = 0); 
	void Print();
	int getX() { return x; } 
	int getY() { return y; }
	void setX(int x) { this->x = x;  }
	void setY(int y) { this->y = y; }
	//The class Line is declared a friend, which means that all of its functions can access to Point's private
	friend class CLine; 

		
};

