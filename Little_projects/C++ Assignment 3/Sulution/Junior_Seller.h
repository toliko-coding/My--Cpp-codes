#pragma once

#include <iostream>
#include <string.h>
#include <typeinfo>

#include "Worker.h"
using namespace std;

class Junior_Seller :public Worker
{
private:
	int* CustumersDeals;
	int numOfDeals;

public:

	//ctr , dtr
	Junior_Seller();
	Junior_Seller(string _name, int _id, float _jopP, int _salary);
	~Junior_Seller();

	//get
	int getNumOfDeals() const;
	float averageSell() const;
	int sumOfallDelas() const;

	//set
	void setNumOfDeals(int _num);
	void increaceNumOfDeals();
	virtual void addDeal(int _deal);



	//VRTBL
	virtual void print();
	virtual float mySalary();

};