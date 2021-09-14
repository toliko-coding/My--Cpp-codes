#pragma once


#include <iostream>
#include <string.h>
#include <typeinfo>

#include "Worker.h"

using namespace std;


class Store
{
private:
	string StoreName;
	string ChainName;
	Worker** listOfWorkers;
	int numOfWorkers;
	int storeId;

public:
	
	//ctr , dtr
	Store();
	Store(string _storeName, string _chainName , int _storeId = 0);
	~Store();

	//get
	string getStoreName() const;
	string getChainName() const;
	int getNumOfWorkers() const;
	int getStoreId() const;

	//set
	void setStoreName(string _name);
	void setChainName(string _name);
	void setStoreId(int id);
	void setNumOfWorkers(int num);
	void increaseNumOfWorkes();

	//special functions
	void addWorker(char type, string _name, int _id, float _job_p , int _salary);
	void makeDeal(int id, int deal);
	void cancelDealById(int id, int deal);
	int getSumOfallSalariesIntheStore();
	void printEmpById(int _empId);
	bool checkIfEmpExsict(int _empId);

	//print store info
	void printStoreInfo();
};
