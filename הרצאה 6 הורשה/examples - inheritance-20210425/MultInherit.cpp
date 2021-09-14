
#include <iostream>
using namespace std;
class A {
	int a;
public:
	A(int x) :a(x) { cout << " A::A(int)" << endl; }
	~A(){ cout << " A::~A()" << endl; }
	void Print()const {
		cout << a << endl;
	}
};
class B  {
	int b;
public:
	B(int x) :b(x) { cout << " B::B(int)" << endl; }
	~B() { cout << " B::~B()" << endl; }
	void Print()const {
		cout << b << endl;
	}
};
class C : public A, public B {
	int c;
public :
	C(int x, int y, int z) :A(x), B(y), c(z) {
		cout << " C::C(int,int,int)" << endl;
	}
	~C(){ cout << " C::~C()" << endl; }

	void Print()const {
		A::Print();
		B::Print();
		cout << c << endl;
	}
};
int main()
{
	A obj1(5);
	obj1.Print();

	B obj2(10);
	obj2.Print();

	C obj3(1, 2, 3);
	obj3.Print();
	cout << endl << endl;
	obj3.B::Print();

	cout << " FINISH !!" << endl;
	return 0;
}

