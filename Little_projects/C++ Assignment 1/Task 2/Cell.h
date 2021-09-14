#ifndef CELL
#define CELL

/*Assignment 1 :
Author : Anatoli Kot , ID : 324413756*/


class Cell
{
private :
	char cell;
	bool free;

public :
	Cell();
	void Print() const;
	void Setter(char); // change the cell + change free value
	char Getter() const;
	bool Is_free() const;
	~Cell();

};


#endif // !CELL
