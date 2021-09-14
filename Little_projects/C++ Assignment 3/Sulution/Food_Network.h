#pragma once

#include <iostream>
#include <string.h>
#include <typeinfo>

#include "Network.h"

using namespace std;

class Food_Network :public Network
{
private:
	int numOfTheSuppliers;

public:
	//ctr , dtr 
	Food_Network();
	Food_Network(string _name, int numOfSuppl = 0);
	~Food_Network();

	//get
	int getNumOfSuppliers() const;

	//set
	void setNumOfSuppliers(int _num);
	void increaseNumOfSuppliers();

	//VRTBL

	virtual void print();
};