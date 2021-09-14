#pragma once
#include "CPoint.h"
class CLine {
	CPoint start, end;
public:
	CLine(int = 0, int = 0, int = 0, int = 0); // 5 ctors inside
	~CLine();//dtor
	void Print();
};
