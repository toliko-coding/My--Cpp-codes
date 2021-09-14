#include "Cell.h"
using namespace std;
#include <iostream>

/*Assignment 1 :
Author : Anatoli Kot , ID : 324413756*/

Cell::Cell():cell(' ') , free(true)
{
	//cout << "--Cell-- Def-Constractor" << endl << endl;
}

void Cell::Print() const
{
	cout << cell << "  ";
}

void Cell::Setter(char newchar)
{
	cell = newchar;
	free = false;
}

char Cell::Getter() const
{
	return cell;
}

bool Cell::Is_free() const
{
	if (free == true)
		return true;
	else
		return false;
}

Cell::~Cell()
{
	cout << "--Cell-- DELETED " << endl;
}
