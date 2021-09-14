#include "Player.h"
#include "Board.h"


/*Assignment 1 :
Author : Anatoli Kot , ID : 324413756*/


class Game {
private:
	Board board;
	Player players[2];
	enum statuses {win,draw,start};
	statuses status;
	char turn;

public:
	Game(char* _name1, char* _name2);
	void play();
	~Game();
	bool winCheck(char _symbol) const;


};