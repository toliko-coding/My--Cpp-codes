#include <iostream>
#include <string.h>
#include <typeinfo>
#include "Worker.h"

using namespace std;


//ctr , dtr
Worker::Worker():name("Unknown") , id(0) , job_pracentage(0),salary(0)
{
	cout << "Created :" << typeid(*this).name() << " - Defualt" << endl;
}

Worker::Worker(string _name, int _id, float _jopP, int _salary):name(_name) , id(_id) , job_pracentage(_jopP) , salary(_salary)
{
	cout << "Created :" << typeid(*this).name() << " - Builer" << endl;

}

Worker::~Worker()
{
	cout << "Deleted :" << typeid(*this).name() << " - Defualt" << endl;

}

//get
int Worker::getSalary() const
{
	return salary;
}

string Worker::getName() const
{
	return name;
}

int Worker::getId() const	
{
	return id;
}


//Also convert the precentage from int to float between 0 to 1 | 75% -->  0.75
float Worker::getJob_p() const
{
	return job_pracentage / 100;
}

//set 

void Worker::setName(string _name)
{
	name = _name;
}

void Worker::setId(int _id)
{
	id = _id;
}

void Worker::setJob_prec(float _job_p)
{
	job_pracentage = _job_p;
}

void Worker::setSalary(int _salary)
{
	salary = _salary;
}


//VRTBL

void Worker::print()
{
	cout << endl << "name : " << name << endl
		<< "id : " << id << endl
		<< "job precentage : " << job_pracentage << "%" << endl
		<< "Salary : " <<mySalary() << endl;
}

float Worker::mySalary()
{
	return salary;
}

void Worker::addDeal(int _deal)
{
	cout << endl<< "** The Employe " << getName() << " cant make Deals , ONLY Junior or Senior can" << endl;
}

void Worker::CancelDeal(int _deal)
{
	cout << endl << "** The Employe " << getName() << "cant cancel Deals , ONLY  Senior can" << endl;

}