#pragma once

#include <iostream>
#include <string.h>
#include <typeinfo>

#include "Worker.h"
#include "Junior_Seller.h"
using namespace std;

class Senior_Seller :public Junior_Seller
{
private:
	int* arrayOfCanceldDeals;
	int numOfCanceldDelas;

public:
	//ctr , dtr 
	Senior_Seller();
	Senior_Seller(string _name, int _id, float _jopP, int _salary);
	~Senior_Seller();

	//get
	int getNumOfCanceldDeals() const;

	//set
	void increaceNumOfCanceldDeals();
	void CancelDeal(int _deal);
	int sumOfallCanceldDeals();



	//VRTBL
	virtual void print();
	virtual float mySalary();

	//DownCasting
	
};