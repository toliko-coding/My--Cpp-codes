#ifndef PLAYER
#define PLAYER


/*Assignment 1 :
Author : Anatoli Kot , ID : 324413756*/


class Player {
private:
	char* name;
	char symbol;
	Player(const Player& other);

public:
	Player();
	Player(char* _name, char _symbol);
	void print() const;
	char* getname() const;
	void setname(char* _name);
	char getsymbol() const;
	void setsymbol(char _symbol);
	int make_move();
	~Player();

};



#endif // !PLAYER