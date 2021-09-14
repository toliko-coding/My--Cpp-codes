#define _CRT_SECURE_NO_WARNINGS
#include "Player.h"
using namespace std;


/*Assignment 1 :
Author : Anatoli Kot , ID : 324413756*/

#include <iostream>

#include <string.h>

Player::Player():name(nullptr) , symbol(' ')
{
}

Player::Player(char* _name, char _symbol)
{


	int size = strlen(_name);
	name = new char[size + 1];
	strcpy(name, _name);


	symbol = _symbol;

}

void Player::print() const
{
	cout << "Player info :" << endl
		<< "the name is :" << name << endl
		<< "the symbol is : " << symbol << endl << endl;
	
}

char* Player::getname() const
{
	return name;
}

void Player::setname(char* _name)
{
	delete[] name;
	int size = strlen(_name) ;
	name = new char[size + 1];

	strcpy(name, _name);
}

char Player::getsymbol() const
{
	return symbol;
}

void Player::setsymbol(char _symbol)
{
	symbol = _symbol;
}

int Player::make_move()
{
	int choose;
	cout << "Player : " << name << " Please choose your move.." << endl;
	cin >> choose;
	if (choose >= 1 && choose <= 9)
		return choose;

	
	else
	{
		while (true)
		{
			cout << "Your choise isnt in range ( 1 - 9 )" << "Please choose again : " << endl;
			cin >> choose;
			if (choose >= 1 && choose <= 9)
				return choose;
		}


	}
}

Player::~Player()
{
	delete[] name;
	cout << "--Player-- name have been deleted" << endl;
}
