#include <iostream>
#include <string.h>
#include <typeinfo>

#include "Food_Network.h"

using namespace std;

Food_Network::Food_Network():Network() , numOfTheSuppliers(0)
{
	//cout << "Created :" << typeid(*this).name() << " - Default" << endl;

}

Food_Network::Food_Network(string _name, int numOfSuppl):Network(_name) , numOfTheSuppliers(numOfSuppl)
{
	//cout << "Created :" << typeid(*this).name() << " - Builder" << endl;

}

Food_Network::~Food_Network()
{
	cout << "Deleted :" << typeid(*this).name() << " - Default" << endl;

}

int Food_Network::getNumOfSuppliers() const
{
	return numOfTheSuppliers;
}

void Food_Network::setNumOfSuppliers(int _num)
{
	numOfTheSuppliers = _num;
}

void Food_Network::increaseNumOfSuppliers()
{
	numOfTheSuppliers += 1;
}

void Food_Network::print()
{
	cout << "This Network is a Food Network" << endl
		<< "The number of Suppliers is : " << getNumOfSuppliers() << endl;

	Network::print();
}
