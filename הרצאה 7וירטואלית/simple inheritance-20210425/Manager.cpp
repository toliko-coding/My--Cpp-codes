#include "Manager.h"
CManager::CManager(string name, float pay, bool salaried) :CEmployee(name, pay), salaried(salaried)
{

}
float CManager::Salary(float hours) const
{
	if (salaried)
		return payRate;
	else
		return CEmployee::Salary(hours);
}
void CManager::Print() const 
{ 
	cout << "\nManager's data :\n";
	if (salaried)
		cout << " Belongs to the salaried";
	else
		cout << " Does not belong to the salaried ";
	
	CEmployee::Print();
}