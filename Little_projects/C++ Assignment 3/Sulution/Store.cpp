
#include <iostream>
#include <string.h>
#include <typeinfo>
#include "Store.h"

#include "Worker.h"
#include "Manager.h"
#include "Cashier.h"
#include "Junior_Seller.h"
#include "Senior_Seller.h"

using namespace std;


//ctr , dtr
Store::Store():StoreName("Unknown") , ChainName("Unknown") , listOfWorkers(nullptr) , numOfWorkers(0) , storeId(0)
{
	//cout << "Created :" << typeid(*this).name() << " - Default" << endl;

}

Store::Store(string _storeName, string _chainName , int _storeId):
	StoreName(_storeName) , ChainName(_chainName) , listOfWorkers(nullptr) , numOfWorkers(0) , storeId(_storeId)
{
	//cout << "Created :" << typeid(*this).name() << " - Builder" << endl;

}

Store::~Store()
{
	if (listOfWorkers != nullptr)
	{
		for (int i = 0; i < numOfWorkers; i++)
		{
			delete listOfWorkers[i];
		}
		delete[] listOfWorkers;
	}

	cout << "Deleted :" << typeid(*this).name() << " - Default" << endl;
	

}

//get
string Store::getStoreName() const
{
	return StoreName;
}

string Store::getChainName() const
{
	return ChainName;
}

int Store::getNumOfWorkers() const
{
	return numOfWorkers;
}

int Store::getStoreId() const
{
	return storeId;
}


//set
void Store::setStoreName(string _name)
{
	StoreName = _name;
}

void Store::setChainName(string _name)
{
	ChainName = _name;
}

void Store::setStoreId(int id)
{
	storeId = id;
}

void Store::setNumOfWorkers(int num)
{
	numOfWorkers = num;
}

void Store::increaseNumOfWorkes()
{
	numOfWorkers += 1;
}

//special function 

void Store::addWorker(char type, string _name, int _id, float _job_p, int _salary)
{
	//MANAGER [ A ]
	if (type == 'a' || type == 'A')
	{
		if (getNumOfWorkers() == 0)
		{
			listOfWorkers = new Worker*[1];
			listOfWorkers[0] = new Manager(_name, _id, _job_p, _salary, 1);
			increaseNumOfWorkes();

			cout << "Welcome first Employe (Manager) : " << _name << " [" << _id << "] " << "To Store : "<<getStoreName() << endl << "Total of Workers : " << getNumOfWorkers() << endl;
		}
		else
		{
			increaseNumOfWorkes();
			Worker** temp = new Worker * [getNumOfWorkers()];

			int i = 0;
			for (i; i < getNumOfWorkers() - 1; i++)
			{
				temp[i] = listOfWorkers[i];
			}
			temp[i] = new Manager(_name, _id, _job_p, _salary, 1);

			delete[] listOfWorkers;
			listOfWorkers = temp;
			cout << "Welcome  Employe (Manager) : " << _name << " [" << _id << "] " << "To Store : " << getStoreName() << endl << "Total of Workers : " << getNumOfWorkers() << endl;


		}
	}

	//Senior Seller [ B ]
	if (type == 'b' || type == 'B')
	{
		if (getNumOfWorkers() == 0)
		{
			listOfWorkers = new Worker * [1];
			listOfWorkers[0] = new Senior_Seller(_name, _id, _job_p, _salary);
			increaseNumOfWorkes();

			cout << "Welcome first Employe (Senior Seller): " << _name << " [" << _id << "] " << "To Store : " << getStoreName() << endl << "Total of Workers : " << getNumOfWorkers() << endl;
		}
		else
		{
			increaseNumOfWorkes();
			Worker** temp = new Worker * [getNumOfWorkers()];

			int i = 0;
			for (i; i < getNumOfWorkers() - 1; i++)
			{
				temp[i] = listOfWorkers[i];
			}
			temp[i] = new Senior_Seller(_name, _id, _job_p, _salary);

			delete[] listOfWorkers;
			listOfWorkers = temp;
			cout << "Welcome  Employe (Senior Seller) : " << _name << " [" << _id << "] " << "To Store : " << getStoreName() << endl << "Total of Workers : " << getNumOfWorkers() << endl;


		}
	}


	//Junior Seller [ C ]
	if (type == 'c' || type == 'C')
	{
		if (getNumOfWorkers() == 0)
		{
			listOfWorkers = new Worker * [1];
			listOfWorkers[0] = new Junior_Seller(_name, _id, _job_p, _salary);
			increaseNumOfWorkes();

			cout << "Welcome first Employe (Junior Seller): " << _name << " [" << _id << "] " << "To Store : " << getStoreName() << endl << "Total of Workers : " << getNumOfWorkers() << endl;
		}
		else
		{
			increaseNumOfWorkes();
			Worker** temp = new Worker * [getNumOfWorkers()];

			int i = 0;
			for (i; i < getNumOfWorkers() - 1; i++)
			{
				temp[i] = listOfWorkers[i];
			}
			temp[i] = new Junior_Seller(_name, _id, _job_p, _salary);

			delete[] listOfWorkers;
			listOfWorkers = temp;
			cout << "Welcome  Employe (Junior Seller) : " << _name << " [" << _id << "] " << "To Store : " << getStoreName() << endl << "Total of Workers : " << getNumOfWorkers() << endl;


		}
	}
	

	//Cashier [ D ]
	if (type == 'd' || type == 'D')
	{
		if (getNumOfWorkers() == 0)
		{
			listOfWorkers = new Worker * [1];
			listOfWorkers[0] = new Cashier(_name, _id, _job_p, _salary , 0);
			increaseNumOfWorkes();

			cout << "Welcome first Employe (Cashier): " << _name << " [" << _id << "] " << "To Store : " << getStoreName() << endl << "Total of Workers : " << getNumOfWorkers() << endl;
		}
		else
		{
			increaseNumOfWorkes();
			Worker** temp = new Worker * [getNumOfWorkers()];

			int i = 0;
			for (i; i < getNumOfWorkers() - 1; i++)
			{
				temp[i] = listOfWorkers[i];
			}
			temp[i] = new Cashier(_name, _id, _job_p, _salary , 0);

			delete[] listOfWorkers;
			listOfWorkers = temp;
			cout << "Welcome  Employe ( Cashier) : " << _name << " [" << _id << "] " << "To Store : " << getStoreName() << endl << "Total of Workers : " << getNumOfWorkers() << endl;


		}
	}
	
}

void Store::makeDeal(int id, int deal)
{
	int i = 0;
	int idx = -1;

	for (i; i < getNumOfWorkers(); i++)
	{
		if (listOfWorkers[i]->getId() == id)
		{
			idx = i;
		}
	}

	if (idx != -1)
	{
		listOfWorkers[idx]->addDeal(deal);
		
	}

	else
		cout << "This id : " << id << " is not Excist" << endl;


}

void Store::cancelDealById(int id, int deal)
{
	int i = 0;
	int idx = 0;
	bool found = 0;
	for (i; i < getNumOfWorkers(); i++)
	{
		if (listOfWorkers[i]->getId() == id)
		{
			found = true;
			idx = i;
		}
	}

	//check 

	if (found)
	{
		//chekc senior
		//down - casting rtti
		Senior_Seller* temp = dynamic_cast <Senior_Seller* > (listOfWorkers[idx]);
		if (temp)
		{ 
			listOfWorkers[idx]->CancelDeal(deal);
		}

		else
		{
			cout << "This Employe  : "<< listOfWorkers[idx]->getName() << "is not a Senior Seller !: "  << endl
				<< "Only Senior Seller can return item (cancel deal)" << endl << endl;
		}

		;
	}

	else
		cout << "** There is no Employe with ID : " << id << endl << endl;

}

int Store::getSumOfallSalariesIntheStore()
{
	int sum = 0;

	for (int i = 0; i < numOfWorkers; i++)
	{
		sum = sum + listOfWorkers[i]->mySalary();
	}
	return sum;
}

void Store::printEmpById(int _empId)
{
	int index = -1;

	for (int i = 0; i < numOfWorkers; i++)
	{
		if (listOfWorkers[i]->getId() == _empId)
		{
			index = i;
		}
	}

	if (index != -1)
	{
		listOfWorkers[index]->print();
	}
	else
	{
		cout << "There is no Employee with the ID : " << _empId << " To print" << endl;
	}
}

bool Store::checkIfEmpExsict(int _empId)
{
	for (int i = 0; i < numOfWorkers; i++)
	{
		if (listOfWorkers[i]->getId() == _empId)
		{
			return true;
		}
	}
	return false;
}

//print
void Store::printStoreInfo()
{
	cout << endl << "Printing Store info.." << endl;
	cout << "Store Name : " << getStoreName() << endl
		<< "Store ID : " << getStoreId() << endl
		<< "Chain Name : " << getChainName() << endl
		<< "Numer of Workers in Store : " << getNumOfWorkers() << endl;

	for (int i = 0; i < getNumOfWorkers(); i++)
	{
		listOfWorkers[i]->print();
		cout << "----------" << endl;
	}
}
