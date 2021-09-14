#include "Supervisor.h"

int main()
{
	//CEmployee object
	CEmployee emp("David",100);
	emp.Print();
	cout << "Salary is :" << emp.Salary(5) << endl;

	//CManager object
	CManager man("Ruth", 2000);
	man.Print();
	cout << "Salary is :" << man.Salary(5) << endl;

	CEmployee temp;
	temp.Print();
	temp = man;  // Slicing
	temp.Print();

	//CSupervisor object
	CSupervisor super;
	super.Print();
	cout << "Salary is :" << super.Salary(5) << endl;
	return 0;
}

