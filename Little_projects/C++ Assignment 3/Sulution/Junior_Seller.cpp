#include <iostream>
#include <string.h>
#include <typeinfo>

#include "Junior_Seller.h"

using namespace std;


//ctr , dtr
Junior_Seller::Junior_Seller() : Worker() , CustumersDeals(nullptr) , numOfDeals(0)
{
	cout << "Created :" << typeid(*this).name() << " - Defualt" << endl;

}

Junior_Seller::Junior_Seller(string _name, int _id, float _jopP, int _salary):
	Worker(_name , _id , _jopP , _salary) , CustumersDeals(nullptr) , numOfDeals(0)
{
	cout << "Created :" << typeid(*this).name() << " - Builder" << endl;

}

Junior_Seller::~Junior_Seller()
{
	cout << "Deleted :" << typeid(*this).name() << " - Defualt" << endl;

}

//get

int Junior_Seller::getNumOfDeals() const
{
	return numOfDeals;
}

float Junior_Seller::averageSell() const
{
	if (getNumOfDeals() == 0)
		return 0;
	else
	return float(sumOfallDelas()) / getNumOfDeals();
}

int Junior_Seller::sumOfallDelas() const
{
	int sum = 0;
	int i = 0;

	for (i; i < getNumOfDeals(); i++)
	{
		sum += CustumersDeals[i];
	}

	return sum;
}

//set

void Junior_Seller::setNumOfDeals(int _num)
{
	numOfDeals = _num;
}

void Junior_Seller::increaceNumOfDeals()
{
	numOfDeals += 1;
}

void Junior_Seller::addDeal(int _deal)
{

	if (getNumOfDeals() == 0)
	{
		increaceNumOfDeals();
		CustumersDeals = new int;
		*CustumersDeals = _deal;

		cout << endl << "Congradulation About your First Deal : " << getName()  << endl;
				cout << "Deal of : " << _deal << " is added by " << getName() << " , Total Deals : " << getNumOfDeals() << endl;

	}

	else
	{
		increaceNumOfDeals();

		int* temp = new int[getNumOfDeals()];

		int i = 0;
		for (i; i < getNumOfDeals() - 1  ; i++)
		{
			temp[i] = CustumersDeals[i];
		}
		temp[i] = _deal;

		delete[] CustumersDeals;
		CustumersDeals = temp;

		cout << "Deal of : " << _deal << " is added by " << getName() << " , Total Deals : " << getNumOfDeals() << endl;


	}
}

//VRTBL

void Junior_Seller::print()
{
	cout << endl << "This Worker is a " << typeid(*this).name() << endl
		<< "Number of Dealse that he did : " << getNumOfDeals() << endl
		<< "Sum of all the Deals : " << sumOfallDelas() << endl
		<< "Average per sale : " << averageSell();

	Worker::print();
	cout << endl;

}

float Junior_Seller::mySalary()
{
	return (getSalary() + averageSell() + getNumOfDeals()) * getJob_p();
}
