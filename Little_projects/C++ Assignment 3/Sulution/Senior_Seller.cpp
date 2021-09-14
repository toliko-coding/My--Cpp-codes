#include <iostream>
#include <string.h>
#include <typeinfo>

#include "Senior_Seller.h"


using namespace std;


//ctr , dtr
Senior_Seller::Senior_Seller():Junior_Seller() , arrayOfCanceldDeals(nullptr) , numOfCanceldDelas(0)
{
//	cout << "Created :" << typeid(*this).name() << " - Default" << endl;

}

Senior_Seller::Senior_Seller(string _name, int _id, float _jopP, int _salary):
	Junior_Seller(_name , _id , _jopP , _salary) , arrayOfCanceldDeals(nullptr) , numOfCanceldDelas(0)
{
	//cout << "Created :" << typeid(*this).name() << " - Builder" << endl;

}

Senior_Seller::~Senior_Seller()
{
	cout << "Deleted :" << typeid(*this).name() << " - Default" << endl;

}

//get

int Senior_Seller::getNumOfCanceldDeals() const
{
	return numOfCanceldDelas;
}

//set

void Senior_Seller::increaceNumOfCanceldDeals()
{
	numOfCanceldDelas += 1;
}

void Senior_Seller::CancelDeal(int _deal)
{


	if (getNumOfCanceldDeals() == 0)
	{
		arrayOfCanceldDeals = new int;
		*arrayOfCanceldDeals = _deal;
		increaceNumOfCanceldDeals();

		cout << endl << " your First Canceld Deal :(" << endl;
		cout << "Deal of : " << _deal << " is Canceld by " << getName() << " , Total Deals that Canceld : " << getNumOfCanceldDeals() << endl;
	}

	else
	{
		increaceNumOfCanceldDeals();

		int* temp = new int[getNumOfCanceldDeals()];

		int i = 0;
		for (i; i < getNumOfCanceldDeals() - 1; i++)
		{
			temp[i] = arrayOfCanceldDeals[i];
		}
		temp[i] = _deal;

		delete[] arrayOfCanceldDeals;
		arrayOfCanceldDeals = temp;

		cout << "Deal of : " << _deal << " is Canceld , Total Deals that Canceld : " << getNumOfCanceldDeals() << endl;
	}
}

int Senior_Seller::sumOfallCanceldDeals()
{
	int i = 0;
	int sum = 0;

	for (i; i < getNumOfCanceldDeals(); i++)
	{
		sum += arrayOfCanceldDeals[i];
	}

	return sum ;
}


//VRTBL

void Senior_Seller::print()
{
	cout << endl << "This Worker is a " << typeid(*this).name() << endl
		<< "Number of Dealse that he Canceld : " << getNumOfCanceldDeals() << endl;
		

	Junior_Seller::print();
	cout << endl;
}

float Senior_Seller::mySalary()
{
	return Junior_Seller::mySalary() * 1.5;
}
