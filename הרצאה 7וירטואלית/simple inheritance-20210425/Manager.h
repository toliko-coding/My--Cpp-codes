#pragma once
#include "Employee.h"
class CManager : public CEmployee {
protected:
	bool salaried;
public:
	CManager(string = "UnListed", float = 100, bool = true); //ctor
	float Salary(float ) const;
	void Print() const;
	bool GetSalared() const { return salaried; }
};
