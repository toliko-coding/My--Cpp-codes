#pragma once
#include <iostream>
#include <string> // for class string
using namespace std;
class CEmployee {
protected:
	string name;
	float payRate;
public:
	CEmployee( string = "Unknown", float = 0.0); // ctor
	string GetName() const;
	float GetPayRate() const;
	float Salary(float) const;
	void Print() const;
};