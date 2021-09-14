#include "Supervisor.h"

int main()
{
	////CEmployee object
	//CEmployee emp("David",100);
	//emp.Print(); // David 100
	//cout << "Salary is :" << emp.Salary(5) << endl;//500
	//cout << "==================================\n";
	////CManager object
	//CManager man("Ruth", 2000);
	//man.Print();//Belongs to the salaried Ruth 2000
	//cout << "Salary is :" << man.Salary(5) << endl;//2000
	//cout << "==================================\n";
	////CEmployee temp;
	////temp.Print();//Unknown 0
	////temp = man;  // Slicing
	////temp.Print();// Ruth 2000

	////CSupervisor object
	//CSupervisor super;
	//super.Print();// 200 Belongs... Super 300
	//cout << "Salary is :" << super.Salary(5) << endl;//500
	//cout << "==================================\n";


	//int choice;
	//CEmployee* ptr;
	//cout << " Enter your choice: 1 - for Employee, 2 - for Manager , 3 - for Supervisor\n";
	//cin >> choice;
	//// Upcasting
	//if (choice == 1)
	//	ptr = new CEmployee("David", 100);
	//else if (choice == 2)
	//	ptr = new CManager("Ruth", 2000);
	//else if (choice == 3)
	//	ptr = new CSupervisor();
	//else
	//	return 1;

	////using polymorphism
	//ptr->Print();
	//cout<<ptr->Salary(5);

	////free memory
	//delete ptr;

	// Array of pointers
	/*int choice;
	CEmployee* ptr[3];
	for (int i = 0; i < 3; i++) {
		cout << " Enter your choice: 1 - for Employee, 2 - for Manager , 3 - for Supervisor\n";
		cin >> choice;
		switch (choice) {
		case 1:
			ptr[i] = new CEmployee("David", 100);
			break;
		case 2:
			ptr[i] = new CManager("Ruth", 2000);
			break;
		case 3:
			ptr[i] = new CSupervisor();
			break;
		default:
			cout << "Invalid choice, try again!\n";
			i--;

		}

	}*/
	//

	////using polymorphism
	//for (int i = 0; i < 3; i++) {
	//	cout << "\n============\n";
	//	cout << " Emploee #" << i + 1 << endl;
	//	ptr[i]->Print();
	//	cout << ptr[i]->Salary(5);
	//	cout << "\n============\n";
	//}

	////free memory
	//for (int i = 0; i < 3; i++) {
	//	delete ptr[i];
	//}

	// Dyn.array of pointers
	int choice, countOfEmployees;
	CEmployee** ptr;
	cout << "\n How many employees : \n";
	cin >> countOfEmployees;
	ptr = new CEmployee*[countOfEmployees];
	for (int i = 0; i < countOfEmployees; i++) {
		cout << " Enter your choice: 1 - for Employee, 2 - for Manager , 3 - for Supervisor\n";
		cin >> choice;
		switch (choice) {
		case 1:
			ptr[i] = new CEmployee("David", 100);
			break;
		case 2:
			ptr[i] = new CManager("Ruth", 2000);
			break;
		case 3:
			ptr[i] = new CSupervisor();
			break;
		default:
			cout << "Invalid choice, try again!\n";
			i--;

		}

	}


	//using polymorphism
	for (int i = 0; i < countOfEmployees; i++) {
		cout << "\n============\n";
		cout << " Emploee #" << i + 1 << endl;
		ptr[i]->Print();
		cout << ptr[i]->Salary(5);
		cout << "\n============\n";
	}

	//free memory
	for (int i = 0; i < countOfEmployees; i++) {
		delete ptr[i];
	}
	delete[] ptr;

	return 0;
}

