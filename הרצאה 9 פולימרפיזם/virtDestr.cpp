#include <iostream>
#include <string>
using namespace std;
class Base {
public:
	virtual void f() { cout << "1 "; }
	 void ff() { cout << "2"; }
	 virtual  ~Base() { cout << "~Base" << endl; }
};
class Derived : public Base {
	int* ptr;
	int size;
public:
	Derived(int size):size(size)	{
		ptr = new int[size];
		for (int i = 0; i < size; i++)
			ptr[i] = 0;
	}
	/*virtual*/ ~Derived() {
		cout << "~Derived" << endl;
		delete[] ptr;
	}
	 void f() { cout << "3 ";  }
	void ff() { cout << "4"; }
};
int main() {
	
	Base* pB = new Derived(3);
	//pB->f();//3
	//pB->ff();//2

	delete pB;
}
























