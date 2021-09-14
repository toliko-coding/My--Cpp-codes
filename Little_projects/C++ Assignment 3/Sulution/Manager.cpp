#include <iostream>
#include <string.h>
#include <typeinfo>

#include "Manager.h"

using namespace std;


//ctr , dtr
Manager::Manager():Worker() , LevelOfManager(1)
{
	cout << "Created :" << typeid(*this).name() << " - Defualt" << endl;
}

Manager::Manager(string _name, int _id, float _jopP, int _salary, int _level): 
	Worker(_name , _id , _jopP , _salary), LevelOfManager(_level)
{
	cout << "Created :" << typeid(*this).name() << " - Builder" << endl;

}

Manager::~Manager()
{
	cout << "Deleted :" << typeid(*this).name() << " - Defualt" << endl;

}

//get
int Manager::getLevelOf_manager()
{
	return LevelOfManager;
}

void Manager::setLevelOf_manager(int newlevel)
{
	LevelOfManager = newlevel;
}

//VRTBL
void Manager::print()
{
	cout << "This Worker is a " << typeid(*this).name() << endl
		<< "Lever is : " << LevelOfManager << endl;
	Worker::print();
}

float Manager::mySalary()
{
	return  (Worker::getSalary() * LevelOfManager) * Worker::getJob_p();
	
}


