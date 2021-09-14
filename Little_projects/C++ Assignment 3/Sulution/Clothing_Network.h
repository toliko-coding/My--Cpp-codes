#pragma once

#include <iostream>
#include <string.h>
#include <typeinfo>

#include "Network.h"

using namespace std;

class Clothing_Network : public Network
{
private:
	string nameOftheSupplier;

public:
	//ctr ,dtr 
	Clothing_Network();
	Clothing_Network(string netWorkName, string nameOfSupplier);
	~Clothing_Network();


	//get
	string getNameOfSupplier() const;
	//set


	//VRTBL
	virtual void print();
};