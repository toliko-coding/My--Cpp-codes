#include "Employee.h"
CEmployee::CEmployee( string name, float pay) :name(name), payRate(pay)
{

}
string CEmployee::GetName() const {
	return name;
}
float CEmployee::GetPayRate() const {
	return payRate;
}
float CEmployee::Salary(float hours) const {
	return hours * payRate;
}
void  CEmployee::Print() const {
	cout << "\n Employee's data : ";
	cout << name << ' ' << payRate << endl;
}