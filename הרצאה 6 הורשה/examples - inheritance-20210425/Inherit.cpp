#include <iostream>
#include <string>
using namespace std;

class A{
protected:
	int f_A;
public:
	A( int num) :f_A(num) {
		cout << " A::A()" << endl;
	}
	void Print()const { 
		cout << "f_A: " << this->f_A << endl; 
	}
	bool operator > (const A &sec) const{ 
		return  f_A > sec.f_A; 
	}
};
// ----------------------------------------------
class B : public A {
private:
	string f_B;
public:
	B(int num, string str) : A(num),f_B(str) { 
		cout << " B::B()" << endl;
	}
	void Print()const { 
		cout << "Object B" << endl;  
		A::Print(); 
		cout << "f_B: " << f_B << endl;
	}
};
// ----------------------------------------------
class C : public A {
private:
	float f_C;
public:
	C(int num, float fnum) : A(num), f_C ( fnum) {
		cout << " C::C()" << endl;
	}
	void Print() const{ 
		cout << "Object C" << endl; 
		A::Print(); 
		cout << "f_C: " << f_C << endl; 
	}
};
// ----------------------------------------------
int main() {
	A a(1);
	B b(2,"test");
	C c(3,4);
	//A a1(100), a2(6);
	//a1.Print();
	//a2.Print();
	//cout << "-------------------------------------" << endl;
	//B b1(17, "table"), b2(19, "London");
	//C c1(23, (float)7.5), c2(6, (float)31.45);
	//b1.Print();
	//c2.Print();
	//if (b2 > b1 && c1 > b2) // 19>17 && 23>19
	//	cout << "1-yes" << endl;
	//else
	//	cout << "1-no" << endl;

	//if (c2 > b1 && b2 > a1)// 6>17 && 19>100
	//	cout << "2-yes" << endl;
	//else
	//	cout << "2-no" << endl;
	//cout << "-------------------------------------" << endl;
	//A na1(5), na3(8);
	//A na2 = na1; //cctor
	//na1.Print();
	//na2.Print();
	//na2 = na3; // =
	//na2.Print();
	//cout << "-------------------------------------" << endl;
	//B nb1(48, "capital");
	//na1 = (A)nb1; // slicing
	//na1.Print();
	//na3 = nb1; // slicing
	//na3.Print();

	return 0;
}