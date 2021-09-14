#pragma once

#include <iostream>
#include <string.h>
#include <typeinfo>

#include "Worker.h"
using namespace std;


class Cashier : public Worker
{
private:
	int numOfDeals;

public:
	//ctr , dtr
	Cashier();
	Cashier(string _name, int _id, float _jopP, int _salary ,int _numOfDeals);
	~Cashier();

	//get
	int getNumofDeals() const;

	//set
	void setNumOfDeals(int _num);

	//virtual teble
	virtual void print();
	virtual float mySalary();
	//virtual void addDeal(int _deal); 

};