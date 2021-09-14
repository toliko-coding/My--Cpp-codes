#include <iostream>
#include <string.h>
#include <typeinfo>

//--------------------------------------------------------------

/* Assignment: 3
Author: Anatoli Kot, ID: 324413756 */

//--------------------------------------------------------------

#include "Worker.h"
#include "Manager.h"
#include "Cashier.h"
#include "Junior_Seller.h"
#include "Senior_Seller.h"

#include "Store.h"
#include "Network.h"
#include "Clothing_Network.h"
#include "Food_Network.h"

using namespace std;


int main()
{



	Network** mainNet = new Network* [3];

	mainNet[0] = new Clothing_Network("Golbary" , "Moshe Gabay");
	mainNet[1] = new Food_Network("Super-Sal", 4);
	mainNet[2] = new Clothing_Network("TNT", "Ruti Sulemani");

	mainNet[0]->addStore("Store", 65);
	mainNet[1]->addStore("Store", 3);
	mainNet[1]->addStore("Store", 81);
	mainNet[2]->addStore("Store", 3);

	bool Menu = true;

	

	while (Menu)
	{
		cout << "------ M-E-N-U ------" << endl
			<< "Please Choose what you want to do from the menu :" << endl
			<< "1.Add Shop" << endl
			<< "2.Add Employee" << endl
			<< "3.Shopping" << endl
			<< "4.Return Item" << endl
			<< "5.Print Chain" << endl
			<< "6.Sum Salaries Chain" << endl
			<< "7.Sum Salaries Shop" << endl
			<< "8.Print Shop" << endl
			<< "9.Print Employee" << endl
			<< "10.Exit" << endl << endl
			<<"===================================" << endl;

		int choise;
		cin >> choise;
		// ---------------- 1 ----------------- ADD SHOP
		if (choise == 1)
		{
			cout << "Please Enter the Name of the Chain that you want to add a Store to [ Golbary , Super-Sal , TNT ] : " << endl;
			string _name;
			cin >> _name;

			cout << endl << "Please Enter The ID of the new Store : " << endl;
			int _id;
			cin >> _id;
			cout << endl;

			//---

			for (int i = 0; i < 3; i++)
			{
				if (mainNet[i]->getNameNetwork() == _name)
				{
					if (mainNet[i]->checkStoreId(_id) == true)
					{
						cout << "This Store id : " << _id << " is alreay Exict " << endl;
					}
					else
					{
						mainNet[i]->addStore("Store", _id);
					}
				}
			}

		}
		// ---------------- 2 ----------------- ADD EMPLOYEE
		if (choise == 2)
		{
			//type
			cout << "Please Enter Employee Type : " << endl
				<< "[ A ] - Manager(Level1)" << endl
				<< "[ B ] - Senior Seller" << endl
				<< "[ C ] - Junior Seller" << endl
				<< "[ D ] - Cashier" << endl;

			char type;
			cin >> type;

			//name
			cout << endl << "Please Enter the name of the Employee : " << endl;
			string name;
			cin >> name;

			//id
			cout << endl << "Please Enter Employee ID : " << endl;
			int id;
			cin >> id;

			// job precentage
			cout << endl << "Please Enter the Job precentage of this Employee : " << endl;
			float job_p;
			cin >> job_p;

			//salary
			cout << endl << "Please Enter His basic Salary : " << endl;
			int salary;
			cin >> salary;

			//Chain name
			cout << endl << "Please Enter the Name of the Chain you want to add this Employee  [ Golbary , Super-Sal , TNT ] : " << endl;
			string chainName;
			cin >> chainName;

			//Sore ID
			cout << endl << "Please Enter the ID of the store you want him to work : " << endl;
			int storeId;
			cin >> storeId;

			




			//find Chain 
			int index = -1; // chain index

			for (int i = 0; i < 3; i++)
			{
				if (mainNet[i]->getNameNetwork() == chainName)
				{
					index = i;
				}
			}

			if (index != -1)
			{
				if (mainNet[index]->checkIfEmpExsict(id) == false)
					mainNet[index]->addEmploye(storeId, type, name, id, job_p, salary);
				else
					cout << "There is already Employee with the id : " << id << " in this Chain" << endl;
			}

			else
			{
				cout << "There is no Chain with name : " << name << " only [ Golbary , Super-Sal , TNT ] " << endl;
			}

				 
		}
		// ---------------- 3 ----------------- SHOPPING
		if (choise == 3)
		{
			//Chain name
			cout << endl << "Please Enter the Name of the Chain you want to do shopping :  [ Golbary , Super-Sal , TNT ] " << endl;
			string _chainName;
			cin >> _chainName;

			//Store id
			cout << endl << "Please Enter Store ID : " << endl;
			int _storeId;
			cin >> _storeId;

			//deal 
			cout << endl << "Please Enter the amount of the Deal" << endl;
			int _deal;
			cin >> _deal;

			//which employee ? get by id;
			cout << endl << "Please Enter the ID of the Employee that did the Deal : " << endl;
			int _empId;
			cin >> _empId;


			int index = -1;
			//find chain
			for (int i = 0; i < 3; i++)
			{
				if (mainNet[i]->getNameNetwork() == _chainName)
				{
					index = i;
				}
			}

			if (index != -1)
			{
				//check store id
				if (mainNet[index]->checkStoreId(_storeId))
				{
					mainNet[index]->doShopping(_storeId, _empId, _deal);
				}
				else
				{
					cout << endl << "in the Chain : " << _chainName << " There is no store with the ID : " << _storeId << endl;
				}
			}

			else
			{
				cout << endl << "There is no Chain with the name : " << _chainName << " for the list :  [ Golbary , Super-Sal , TNT ] " << endl;
			}


		}

		// ---------------- 4 ----------------- Return Item ( Cancel Deal ) 
		if (choise == 4)
		{
			//chain name
			cout << endl << "Please Enter the name of the Chain that you want to return your item  [ Golbary , Super-Sal , TNT ] : " << endl;
			string _chainName;
			cin >> _chainName;

			//Store ID
			cout << endl << "Please Enter the Store ID : " << endl;
			int _storeId;
			cin >> _storeId;

			//cancel deal
			cout << endl << "Please Enter the amout of the Deal you want to return : " << endl;
			int _deal;
			cin >> _deal;

			//employee id
			cout << endl << "Please Enter the ID of the Employee that cancel the Deal" << endl;
			int _empId;
			cin >> _empId;

			//find chain
			int index = -1;

			for (int i = 0; i < 3; i++)
			{
				if (mainNet[i]->getNameNetwork() == _chainName)
				{
					index = i;
				}
			}

			

			if (index != -1)
			{
				if (mainNet[index]->checkStoreId(_storeId))
				{
					mainNet[index]->returnItem(_storeId, _empId, _deal);
				}
				else
				{
					cout << endl << "in the Chain : " << _chainName << " There is no store with the ID : " << _storeId << endl;
				}

			}

			else
			{
				cout << "There is no Chain with the name : " << _chainName << " from the list  [ Golbary , Super-Sal , TNT ] : " << endl;
			}
			
		}

		// ---------------- 5 ----------------- Print Chain
		if (choise == 5)
		{
			cout << endl << "Please Enter witch Chain you want to print  [ Golbary , Super-Sal , TNT ] : " << endl;
			string _chainName;
			cin >> _chainName;

			int index = -1;

			for (int i = 0 ; i < 3; i++)
			{
				if (mainNet[i]->getNameNetwork() == _chainName)
				{
					index = i;
				}
			}

			if (index != -1)
			{
				mainNet[index]->print();
			}

			else
			{
				cout << "There is no Chain with the name : " << _chainName << " in the list :   [ Golbary , Super-Sal , TNT ]" << endl;
			}
		}


		// ---------------- 6 ----------------- Print Sum of Salaries in the Chain
		if (choise == 6)
		{
			cout << endl << "Please Enter the name of the Chain that you want to see the sum of the salaries  [ Golbary , Super-Sal , TNT ] : " << endl;
			string _chainName;
			cin >> _chainName;

			int index = -1;

			for (int i = 0; i < 3; i++)
			{
				if (mainNet[i]->getNameNetwork() == _chainName)
				{
					index = i;
				}
			}

			if (index != -1)
			{
				cout << endl << "The Sum off all the Employes in the chain : " << _chainName<< " is : " << mainNet[index]->getAllChainSalaries()<< endl;
			}

			else
			{
				cout << "There is no Chain with the name : " << _chainName << " in the list :   [ Golbary , Super-Sal , TNT ]" << endl;
			}

		}

		// ---------------- 7 ----------------- Print Sum of Salaries in the Store
		if (choise == 7)
		{
			cout << endl << "Please Enter the name of the Chain :  [ Golbary , Super-Sal , TNT ] " << endl;
			string _chainName;
			cin >> _chainName;

			cout << endl << "Please Enter the Store ID : " << endl;
			int _storeId;
			cin >> _storeId;

			int index = -1;

			for (int i = 0; i < 3; i++)
			{
				if (mainNet[i]->getNameNetwork() == _chainName)
				{
					index = i;
				}
			}

			if (index != -1)
			{
				cout << "The Sum of the Salaries in Store ID : " << _storeId << " in Chain : " << _chainName << " is : " <<mainNet[index]->getSumSaleriesOfStoreById(_storeId) << endl;
			}
			else
			{
				cout << endl << "There is no Chain with the name : " << _chainName << " form the list :  [ Golbary , Super-Sal , TNT ] " << endl;
			}
		}


		// ---------------- 8 ----------------- Print Shop
		if (choise == 8)
		{

			cout << endl << "Please Enter the Name of the Chain :[ Golbary , Super-Sal , TNT ] " << endl;
			string _chainName;
			cin >> _chainName;

			cout << endl << "Please Enter the ID of the Store you want to print : " << endl;
			int _storeId;
			cin >> _storeId;

			int index = -1;

			for (int i = 0; i < 3; i++)
			{
				if (mainNet[i]->getNameNetwork() == _chainName)
				{
					index = i;
				}
			}

			if (mainNet[index]->checkStoreId(_storeId))
			{
				mainNet[index]->print();
			}
			else
			{
				cout << endl << "There is no Store with the ID : " << _storeId << " in the Chain " << _chainName << endl;
			}

		}



		// ---------------- 9 ----------------- Print Employee

		if (choise == 9)
		{
			cout << endl << "Please Enter the Name of The Chain :[ Golbary , Super-Sal , TNT ] " << endl;
			string _chainName;
			cin >> _chainName;

			cout << endl << "Please Enter the ID of the Employee : " << endl;
			int _empId;
			cin >> _empId;

			int index = -1;
			for (int i = 0; i < 3; i++)
			{
				if (mainNet[i]->getNameNetwork() == _chainName)
				{
					index = i;
				}
			}

			if (index != -1)
			{
				mainNet[index]->printEmpById(_empId);
			}
			else
			{
				cout << endl << "There is no Cain with the Name " << _chainName << " form the list : :[ Golbary , Super-Sal , TNT ] " << endl;
			}
		}


		// ---------------- 10 -----------------Exit

		if (choise == 10)
		{
			Menu = false;
		}
	}

	
	//delete 
	for (int i = 0; i < 3; i++)
	{
		delete mainNet[i];
	}

	delete[] mainNet;

	
	return 0;
}

