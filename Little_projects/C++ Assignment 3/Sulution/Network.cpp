#include <iostream>
#include <string.h>
#include <typeinfo>
#include "Network.h"
#include "Senior_Seller.h"

using namespace std;


//ctr dtr
Network::Network():nameOfTheNetwork("Unknown") , listOfStores(nullptr) , numOfStores(0)
{
	//cout << "Created :" << typeid(*this).name() << " - Default" << endl;

}

Network::Network(string _name):nameOfTheNetwork(_name) , listOfStores(nullptr), numOfStores(0)
{
	//cout << "Created :" << typeid(*this).name() << " - Builder" << endl;

}

Network::~Network()
{
	if (listOfStores != nullptr)
	{
		for (int i = 0; i < numOfStores; i++)
		{
			delete listOfStores[i];
		}
		delete[] listOfStores;
	}
	cout << "Deleted :" << typeid(*this).name() << " - Default" << endl;

}

//get
string Network::getNameNetwork() const
{
	return nameOfTheNetwork;
}

int Network::getNumOfStores()
{
	return numOfStores;
}

//set
void Network::setNameNetwork(string _name)
{
	nameOfTheNetwork = _name;
}

void Network::setNumOfStores(int num)
{
	numOfStores = num;
}

void Network::increaseNumOfStores()
{
	numOfStores += 1;
}


//special functions
void Network::addStore(string _storeName , int _storeId)
{
	if (getNumOfStores() == 0)
	{
		listOfStores = new Store*;
		*listOfStores = new Store(_storeName, getNameNetwork(), _storeId);
		cout << "Congradulation about your first shop" << endl
			<< "Shop : " << _storeName << " [" << _storeId << "] is added to Network :" << getNameNetwork() << endl;
		increaseNumOfStores();

	}

	else
	{
		increaseNumOfStores();
		Store** temp = new Store * [getNumOfStores()];
		int i = 0;

		for (i; i < getNumOfStores() - 1; i++)
		{
			temp[i] = listOfStores[i];
		}

		temp[i] = new Store(_storeName, getNameNetwork(), _storeId);
		delete[] listOfStores;
		listOfStores = temp;
		cout << "Shop : " << _storeName << " [" << _storeId << "] is added to Network :" << getNameNetwork() << endl;

	}


}

bool Network::checkStoreId(int _id) const
{
	for (int i = 0; i < numOfStores; i++)
	{
		if (listOfStores[i]->getStoreId() == _id)
			return true;
	}

	return false;
}

void Network::addEmploye(int _storeId, char _type, string _name, int _id, float _job_p, int _salary)
{
	int index = -1;
	for (int i = 0; i < numOfStores; i++)
	{
		if (listOfStores[i]->getStoreId() == _storeId)
		{
			index = i;
		}
	}

	if (index != -1)
	{
		listOfStores[index]->addWorker(_type, _name, _id, _job_p, _salary);
	}
	else
	{
		cout << "There is no Store with the ID : " << _storeId << " that exict in this Network" << endl;
	}
}

void Network::doShopping(int _storeId, int _empId, int _deal)
{
	
	int index = -1;
	for (int i = 0; i < numOfStores; i++)
	{
		if (listOfStores[i]->getStoreId() == _storeId)
		{
			index = i;
			
		}
	}

	if (index != -1)
	{
		if (listOfStores[index]->getNumOfWorkers() > 0)
		{
			listOfStores[index]->makeDeal(_empId, _deal);
		}
		else
		{
			cout << endl << "There is no Emplooyes in the store with the ID : " << _empId << " in this Chain" << endl;

		}
	}
	else
	{
		cout << endl << "There is no store with the ID : " << _storeId << " in this Chain" << endl;
	}
}

void Network::returnItem(int _storeId, int _empId, int _deal)
{
	int index = -1;
	//find store
	for (int i = 0; i < numOfStores; i++)
	{
		if (listOfStores[i]->getStoreId() == _storeId)
		{
			index = i;
		}
	}
	
	if (index != -1)
	{
		if (listOfStores[index]->getNumOfWorkers() > 0)
		{
			listOfStores[index]->cancelDealById(_empId, _deal);
		}
		else
		{
			cout << "There Are no Employess in this Store" << endl;
		}

	}
	else
	{
		cout << "There is no Store with the ID : " << _storeId << " in this Chain" << endl;
	}

	

}

int Network::getAllChainSalaries()
{
	int sum = 0;

	for (int i = 0; i < numOfStores; i++)
	{
		sum = sum + listOfStores[i]->getSumOfallSalariesIntheStore();
	}
	return sum;
}

int Network::getSumSaleriesOfStoreById(int _storeId)
{
	int sum = 0;
	int index = -1;
	for (int i = 0; i < numOfStores; i++)
	{
		if (listOfStores[i]->getStoreId() == _storeId)
		{
			index = i;
		}
	}

	if (index != -1)
	{
		sum = listOfStores[index]->getSumOfallSalariesIntheStore();
	}
	else
	{
		cout << endl << "There is no Store with the ID : " << _storeId << endl;
	}
		return sum;;
}

void Network::printEmpById(int _empId)
{
	int index = -1;
	for (int i = 0; i < numOfStores; i++)
	{
		if(listOfStores[i]->checkIfEmpExsict(_empId))
		{
			index = i;
		}
	}

	if (index != -1)
	{
		listOfStores[index]->printEmpById(_empId);
	}
	else
	{
		cout << endl << "This Employee with the ID : " << _empId << " is not excist" << endl;
	}
}

bool Network::checkIfEmpExsict(int _empId) const
{
	for (int i = 0; i < numOfStores; i++)
	{
		if (listOfStores[i]->checkIfEmpExsict(_empId))
		{
			return true;
		}
	}
	return false;
}


//VRTBL
void Network::print()
{
	cout << "Name of the Network : " << getNameNetwork() << endl
		<< "Number of Stores in the Network : " << getNumOfStores() << endl
		<< "printing Stores info.... :" << endl;

	for (int i = 0; i < getNumOfStores(); i++)
	{
		listOfStores[i]->printStoreInfo();
	}

	cout << endl << endl;
}
