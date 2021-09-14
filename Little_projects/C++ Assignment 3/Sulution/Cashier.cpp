#include <iostream>
#include <string.h>
#include <typeinfo>

#include "Cashier.h"

using namespace std;


//ctr , dtr

Cashier::Cashier():Worker(),numOfDeals(0)
{
	//cout << "Created :" << typeid(*this).name() << " - Defualt" << endl;

}

Cashier::Cashier(string _name, int _id, float _jopP, int _salary , int _numOfDeals):
	Worker(_name , _id , _jopP , _salary) , numOfDeals(_numOfDeals)
{
	//cout << "Created :" << typeid(*this).name() << " - Builder" << endl;

}

Cashier::~Cashier()
{
	cout << "Deleted :" << typeid(*this).name() << " - Defualt" << endl;

}

//get
int Cashier::getNumofDeals() const
{
	return numOfDeals;
}

//set
void Cashier::setNumOfDeals(int _num)
{
	numOfDeals = _num;
}

//VRTBL

void Cashier::print()
{
	cout << endl <<  "This Worker is a " << typeid(*this).name() << endl
		<< "Number of Dealse that he did : " << getNumofDeals() << endl;

	Worker::print();
	cout << endl;

}

float Cashier::mySalary()
{
	return ((getSalary() + getNumofDeals()) * getJob_p());
}
//
//void Cashier::addDeal(int _deal)
//{
//	numOfDeals += 1;
//	cout << "Cashir Deals ++ " << endl;
//}


