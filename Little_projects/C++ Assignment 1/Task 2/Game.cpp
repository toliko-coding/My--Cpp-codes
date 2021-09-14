#define _CRT_SECURE_NO_WARNINGS
#include "Game.h"
#include <iostream>
#include <cstring>
#include <random>

/*Assignment 1 :
Author : Anatoli Kot , ID : 324413756*/

using namespace std;

Game::Game(char* _name1, char* _name2)
{
	board.setboard(9);
	//cout << " -----------------------------------" << endl << " ---------------------------------------" << endl << " -------------------------------- - " << endl;

	players[0].setname(_name1);
	players[0].setsymbol('X');

	players[1].setname(_name2);
	players[1].setsymbol('O');

	cout << "Welcome to my game " << players[0].getname() << " and " << players[1].getname() << endl << endl;

	Game::status = start;

	srand(time(nullptr));

	int choose = rand() % 2;

	if (choose)
		turn = 'X';
	else
		turn = 'O';

	
	if (players[0].getsymbol() == turn)
	{
		players[0].print();
		cout << endl << "You will begin , please choose your move " << endl;
	}
	else
	{
		players[1].print();
		cout << endl << "You will begin , please choose your move " << endl;
	}
}

void Game::play()
{
	while (Game :: status == start)
	{

		board.print();

		if (players[0].getsymbol() == turn)
		{

			cout << endl << "please choose your move :" << endl << players[0].getsymbol() << endl;
			int move = board.set_symbol(players[0].make_move(), players[0].getsymbol());
			if (move == true)
			{
				turn = players[1].getsymbol();
				system("cls");
				if (winCheck(players[0].getsymbol()) == true)
				{
					
					cout << " YOU ARE THE WINNER !" << endl;
					players[0].print();
					Game::status = win;
				}
			}

		}
		else
		{
			cout << endl << " please choose your move " << endl << players[1].getsymbol() << endl;;
			int move = board.set_symbol(players[1].make_move(), players[1].getsymbol());
			if (move == true)
			{
				turn = players[0].getsymbol();
				system("cls");
				if (winCheck(players[1].getsymbol()) == true)
				{
					Game::status = win;
					cout << " YOU ARE THE WINNER !" << endl;
					players[1].print();
				}

			}

		}

		if (board.Count_board() == 0 and Game :: status != win)
		{
			Game::status = draw;
			cout << " DRAW" << endl;
		}

	}
	
}

Game::~Game()
{
	cout << "--Game-- Deleted !" << endl;
}

bool Game::winCheck(char _symbol) const
{ 
	char c1, c2, c3, c4, c5, c6, c7, c8, c9;
	c1 = board.get_symbol(1);
	c2 = board.get_symbol(2);
	c3 = board.get_symbol(3);
	c4 = board.get_symbol(4);
	c5 = board.get_symbol(5);
	c6 = board.get_symbol(6);
	c7 = board.get_symbol(7);
	c8 = board.get_symbol(8);
	c9 = board.get_symbol(9);

	//row

	if (c1 == _symbol and c2 == _symbol and c3 == _symbol)
		return true;

	if (c4 == _symbol and c5 == _symbol and c6 == _symbol)
		return true;

	if (c7 == _symbol  and c8 == _symbol  and c9 == _symbol)
		return true;

	//col

	if (c1 == _symbol and c4 == _symbol and c7 == _symbol)
		return true;

	if (c5 == _symbol and c2 == _symbol and c8 == _symbol)
		return true;

	if (c9 == _symbol and c6 == _symbol and c3 == _symbol)
		return true;

	//cross


	if (c7 == _symbol and c5 == _symbol and c3 == _symbol)
		return true;

	if (c1 == _symbol and c5 == _symbol and c9 == _symbol)
		return true;

	return false;

}
