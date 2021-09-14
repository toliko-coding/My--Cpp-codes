//example 2_1
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//using namespace std;
//class Error {
//private:
//	char* msg;
//public:
//	Error(const char* str) {//ctor
//		cout << "ctor\n";
//		msg = new char[strlen(str) + 1];
//		strcpy(msg, str);
//	}
//	Error(const Error& e) {//cctor
//		cout << "cctor\n";
//		msg = new char[strlen(e.msg) + 1];
//		strcpy(msg, e.msg);
//	}
//	~Error() {//dtor
//		cout << "dtor\n";
//		delete[] msg;
//	}
//	void print() const {
//		cout << msg;
//	}
//};
//
//void foo1() {
//	throw Error("err...");
//
//}
//
//void foo2() {
//	try {
//		foo1();
//	}
//	catch (Error& e) {
//		cout << "foo2 caught: ";
//		e.print();
//		cout << endl;
//		throw;
//	}
//}
//
//int main() {
//	try {
//		foo2();
//		cout << " continue of main: " << endl;
//	}
//	catch (Error& e) {
//		cout << "main caught: ";
//		e.print();
//		cout << endl;
//		cout << " End  main-catch " << endl;
//		return 0;
//	}
//
//	//only get here if there was no exception:
//	cout << " End !" << endl;
//	return 0;
//}


////example 2_2
//#include <iostream>
//#include <string>
//using namespace std;
//class A {
//public:
//	A(string const& name) :m_name(name)
//	{
//		cout << "A::A("<< m_name << ")\n";
//	}
//	~A()
//	{
//		cout << "A::~A(" << m_name << ")\n";
//	}
//private:
//	string m_name;
//};
//
//class B {
//public:
//	B(string const& name, int size)
//		:m_a(name), m_pData(new int[size])
//		, m_size(size)
//	{
//		cout << "B::B(" << m_size << ")\n";
//	}
//	~B() {
//		delete[] m_pData;
//		cout << "B::~B(" << m_size << ")\n";
//	}
//private:
//	A m_a;
//	int m_size;
//	int * m_pData;
//};
//
//int main()
//{
//	try {
//		B b2("Testing...", 1000000000); 
//		//B b2("Testing...", 100);
//	}
//	catch (bad_alloc const & e) {
//		cout << "Error: " << e.what() << "\n";
//	}
//	cout << " End ! \n" ;
//	return 0;
//}
//

