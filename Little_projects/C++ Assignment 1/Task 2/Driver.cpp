#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

/*Assignment 1 :
Author : Anatoli Kot , ID : 324413756*/

using namespace std;
#include<string.h>

#include "Cell.h"
#include "Board.h"
#include "Game.h"
#include "Player.h"

void PrintIntrudaction();



int main()
{

	srand(time(nullptr));
	
	char name1[60];
	cout << "Enter player 1 name :";
	cin >> name1;

	cout << endl << "Enter player 2 name :";
	char name2[60];
	cin >> name2;

	cout << endl << endl;
	
	PrintIntrudaction();

	Game myGame(name1, name2);

	myGame.play();
	
	


	return 0;
};

 void PrintIntrudaction()
{
	 cout << "This is the intrudaction to this game!\n\n"
		 << "U may use the numbers at the right side of the keyboard.\n"
		 << "(Ur Num Lock must be turn on!!)\n"
		 << "like this:\n\n"
		 << "|  1  |  2  |  3  |" << endl
		 << endl

		 << "|  4  |  5  |  6  |" << endl
		 << endl

		 << "|  7  |  8  |  9  |\n\n" << endl
		 << endl;
}


// Cell class cheks :

	/*Cell mycell;

	mycell.Setter('X');
	mycell.Print();
	cout << endl << " the char is : " << mycell.Getter() << endl << mycell.Is_free();
	*/

//------------------------------------------------------------------------

//Board class checks :

	/*Board myboard1;
	Board myboard2(9);

	myboard1.print();
	myboard2.print();

	Board myboard3(myboard2);

	myboard3.print();

	cout << myboard3.Count_board() << endl;
	myboard3.set_symbol(3, 'X');
	cout << myboard3.Count_board() << endl;
	cout << myboard3.get_symbol(3) << endl;
	*/

//------------------------------------------------------------------------
//Player class checks:
/*
char name[20];

cin >> name;



Player p1(name, 'X');
p1.print();

cout << endl << "getname : " << p1.getname() << endl;

char name2[60];
cout << "new name ? : ";
cin >> name2;

p1.setname(name2);
p1.setsymbol('O');
p1.print();

int choose = p1.make_move();
cout << choose << endl;

cout << strlen(p1.getname());
*/


//------------------------------------------------------------------------
//Game class checks :
