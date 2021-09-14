#include <iostream>
using namespace std;
class Acumulator {
	int value;
public:
	Acumulator():value(0) {};
	void Add(int value) {
		this->value += value;
	}
	void Print() const {
		cout << " value is "<<this->value << endl;
	}
	//Declaration of a general function that is a friend, that is, can access the private part of the class in .h
	friend void Reset(Acumulator&); 
};
//Implementation of friend function in .cpp
void Reset(Acumulator& acc) {
	acc.value = 0;
}
int main()
{
	Acumulator myAcc;
	myAcc.Add(10);
	myAcc.Print();
	Reset(myAcc); // call to friend function
	myAcc.Print();
	return 0;
}
