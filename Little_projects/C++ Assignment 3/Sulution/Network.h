#pragma once

#include <iostream>
#include <string.h>
#include <typeinfo>

#include "Store.h"



//--------------------------------------------------------------

/* Assignment: 3
Author: Anatoli Kot, ID: 324413756 */

//--------------------------------------------------------------


using namespace std;

//this class can also be abstract class
class Network
{
private:
	string nameOfTheNetwork;
	Store** listOfStores;
	int numOfStores;
public:

	//ctr , dtr
	Network();
	Network(string _name);
	virtual ~Network();

	//get
	string getNameNetwork() const;
	int getNumOfStores();


	//set
	void setNameNetwork(string _name);
	void setNumOfStores(int num);
	void increaseNumOfStores();


	//special functions
	void addStore(string _storeName , int _storeId); 
	bool checkStoreId(int _id) const ;//true if the id is exist
	void addEmploye(int _storeId, char _type, string _name, int _id, float _job_p, int _salary);
	void doShopping(int _storeId, int _empId, int _deal);
	void returnItem(int _storeId, int _empId, int _deal);
	int getAllChainSalaries();
	int getSumSaleriesOfStoreById(int _storeId);
	void printEmpById(int _empId);
	bool checkIfEmpExsict(int _empId) const;


	//VRTBL
	virtual void print();
};