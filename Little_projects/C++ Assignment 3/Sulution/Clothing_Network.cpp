#include <iostream>
#include <string.h>
#include <typeinfo>

#include "Clothing_Network.h"

using namespace std;

Clothing_Network::Clothing_Network():Network() , nameOftheSupplier("No Supplier yet")
{
	//cout << "Created :" << typeid(*this).name() << " - Default" << endl;

}

Clothing_Network::Clothing_Network(string netWorkName, string nameOfSupplier):Network(netWorkName) , nameOftheSupplier(nameOfSupplier)
{
	//cout << "Created :" << typeid(*this).name() << " - Builder" << endl;

}

Clothing_Network::~Clothing_Network()
{
	cout << "Deleted :" << typeid(*this).name() << " - Default" << endl;


}

string Clothing_Network::getNameOfSupplier() const
{
	return nameOftheSupplier;
}

void Clothing_Network::print()
{
	cout << "This Network is a Clothing Network" << endl
		<< "The Supplier is : " << getNameOfSupplier() << endl;

	Network::print();
}
