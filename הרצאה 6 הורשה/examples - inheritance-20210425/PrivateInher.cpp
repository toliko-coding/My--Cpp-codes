#include <iostream>
using namespace std;

class Top {
public:
	int SeeMe;
};
// ----------------------------------------------
class Middle : private Top {

public:
	void WatchThis( ){
		SeeMe = 10; //ok
	}
	
};
// ----------------------------------------------
class Bottom : public Middle {

public:
	
	void TryThisOut() const {
		//SeeMe = 1; //error
	}
};
// ----------------------------------------------
int main() {
	Top to;
	to.SeeMe = 20; //OK
	//Middle mid;
	//mid.SeeMe = 14;//error !
	//Bottom bot;
	//bot.SeeMe = 20;//error !

	return 0;
}