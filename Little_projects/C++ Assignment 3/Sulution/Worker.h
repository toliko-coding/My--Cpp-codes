#pragma once

#include <iostream>
#include <string.h>
#include <typeinfo>



//--------------------------------------------------------------

/* Assignment: 3
Author: Anatoli Kot, ID: 324413756 */

//--------------------------------------------------------------


using namespace std;

//abstract
class Worker
{
private:
	string name;
	int id;
	float job_pracentage;
	int salary;

public:
	//ctr , dtr
	Worker();
	Worker(string _name , int _id, float _jopP, int _salary);
	virtual ~Worker();


	//get
	 int getSalary() const ;
	 string getName() const;
	 int getId() const;
	 float getJob_p() const ;


	//set
	 void setName(string _name);
	 void setId(int _id);
	 void setJob_prec(float _job_p);
	 void setSalary(int _salary);

	 //virtual
	 virtual void print();
	 virtual float mySalary() = 0; // PURE virtual class
	 virtual void addDeal(int _deal); // for Junior 
	 virtual void CancelDeal(int _deal); // for Senior


	
};




