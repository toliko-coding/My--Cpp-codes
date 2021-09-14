#include "Cell.h"

/*Assignment 1 :
Author : Anatoli Kot , ID : 324413756*/

#ifndef BOARD
#define BOARD



class Board {

private :
	Cell* board;
	int size;

public:
	Board();
	Board(int newsize);
	void print()const;
	Board(const Board& other);
	~Board();
	void setboard(int newsize);
	int getSize() const { return size; };

	bool set_symbol(int cellnum, char symbol);
	int Count_board() const;
	char get_symbol(int cellnum) const;

};


#endif // !BOARD(