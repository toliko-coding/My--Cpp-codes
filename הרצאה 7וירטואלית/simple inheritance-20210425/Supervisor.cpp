#include "Supervisor.h"
CSupervisor::CSupervisor(string name, float pay, bool salaried, float bonus) 
	:CManager(name, pay, salaried), bonus(bonus)
{
}
void CSupervisor::Print() const
{
	cout << "\nSupervisor's data :\n"
		<<bonus<<endl;
	CManager::Print();

}
float CSupervisor::Salary(float hours)const
{
	return CEmployee::payRate + bonus;
}