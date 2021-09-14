#pragma once
#include "Manager.h"
class CSupervisor : public CManager {
	float bonus;
public:
	CSupervisor(string="Super", float=300.0, bool=true, float=200.0);
	void Print() const;
	float Salary(float)const;
};
