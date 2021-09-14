#pragma once

#include <iostream>
#include <string.h>
#include <typeinfo>

#include "Worker.h"

using namespace std;

class Manager : public Worker
{
private:
		
	int LevelOfManager;


public:
	Manager();
	Manager(string _name, int _id, float _jopP, int _salary , int _level);
	~Manager();

	//get
	int getLevelOf_manager();

	//set
	void setLevelOf_manager(int newlevel);

	//VRTBL 
	virtual void print();
	virtual float mySalary();
};