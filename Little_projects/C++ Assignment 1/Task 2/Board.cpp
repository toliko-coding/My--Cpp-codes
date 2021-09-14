#include "Board.h"
using namespace std;
#include <iostream>

/*Assignment 1 :
Author : Anatoli Kot , ID : 324413756*/

Board::Board() :board(nullptr) , size(0)
{
	//cout << "--Board-- Object Created , size = 0 " << endl;
}

Board::Board(int newsize)
{
	size = newsize;

	board = new Cell[size];
	//cout << "--Board-- [Array] object created size = " << size << endl << endl;;
}

void Board::print() const
{
	cout << endl << endl;
	
		


	int counter = 1;
	cout << "|  ";

	for (int i = 0; i < size; i++)
	{
		

		


		board[i].Print();
	
		cout << "|  ";

		if (counter % 3 == 0)
		{
			cout << endl;
			
			cout << endl;

			cout << endl;

			cout << "|  ";

		}
		counter++;
	}
}

Board::Board(const Board& other)
{
	size = other.size;
	board = new Cell[size];

	

	for (int i = 0; i < size; i++)
	{
		board[i] = other.board[i];
		cout << "copying.. ";
	}

	
	cout << endl;
	cout << "--Board-- Object copy have been completed" << endl;
	cout << endl;


}

Board::~Board()
{
	delete[] board;
	cout << "--Board-- Object have been deleted !" << endl;
}

void Board::setboard(int newsize)
{
	size = newsize;

	board = new Cell[size];
	//cout << "--Board****2-- [Array] object created size = " << size << endl << endl;;
}

bool Board::set_symbol(int cellnum, char symbol)
{
	if (board[cellnum - 1].Getter() == ' ')
	{
		board[cellnum - 1].Setter(symbol);
		return true;
	}
	else
	{
		cout << " Board : this place is already taken" << endl;
		cout << "please Choose Again :" << endl <<endl;
		return false;
	}
}

int Board::Count_board() const
{
	int counter = 0;

	for (int i = 0; i < size; i++)
	{
		if (board[i].Is_free())
		{
			counter++;
			
		}
	}
	
	return counter;
}

char Board::get_symbol(int cellnum) const
{
	return board[cellnum - 1].Getter();
}
