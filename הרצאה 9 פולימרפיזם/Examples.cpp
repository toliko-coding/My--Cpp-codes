#include <iostream>
#include <string>
using namespace std;
//1
//class Base {
//public:
//	virtual void f1(){ cout<<" 1 "<<endl; }
//	virtual void f2() { cout << " 2 " << endl; }
//	void f3() { cout << " 3 " << endl; }
//
//};
//class D1 : public Base {
//public:
//	void f1() { cout << " 4 " << endl; }
//};
//class D2 : public Base {
//public:
//	void f2() { cout << " 5 " << endl; }
//	virtual void f4() { cout << " 6 " << endl; }
//};
//int main()
//{
//	Base* ptr = new D1();
//	ptr->f1();//?
//	ptr->f2();//?
//	ptr->f3();//?
//	//ptr->f4();//?
//	return 0;
//}
//2
//class Shape {
//protected:
//	int width, height;
//public:
//	Shape(int a = 0, int b = 0):width ( a), height ( b){}
//	virtual int area() = 0;
//};
//class Rectangle : public Shape {
//public:
//	Rectangle(int a = 0, int b = 0) :Shape(a, b) { }
//	 int area() {
//		cout << "Rectangle class area :" ;		return (width * height);
//	}
//};
//class Triangle : public Shape {
//public:
//	Triangle(int a = 0, int b = 0) :Shape(a, b) { }
//	int area() {
//		cout << "Triangle class area :";		return (width * height / 2);
//	}
//};
//// Main function for the program
//int main() {
//	Shape *shape;
//	Rectangle rec(10, 7);
//	Triangle  tri(10, 5);
//	// store the address of Rectangle
//	shape = &rec;
//	// call rectangle area.
//	cout<<shape->area()<<endl;
//	// store the address of Triangle
//	shape = &tri;
//	// call triangle area.
//	cout<<shape->area()<<endl;
//	return 0;
//}

//3
//class A {
//public:
//	A(const long& id) : id(id) {
//		cout << "A::ctor" << endl;
//	}
//	A(const A& s) { cout << "A::copy ctor" << endl; } 
//	virtual ~A() { cout << "A::dtor" << endl; } 
//	void f1() { cout << "A::f1()" << endl; f2(); }
//	virtual void f2() = 0;
//private:
//	long id;
//
//};
//
//class B1 : virtual public A {
//public:
//	B1(const long& id, const char* name): _sName1(name), A(id) {
//		cout << "B1::ctor" << endl;
//	}
//	B1(const B1& b1) : A(b1) { cout << "B1::copy ctor" << endl; }
//	~B1() { cout << "B1:dtor" << endl; }
//	virtual void f1() { cout << "B1::f1()" << endl; }
//	virtual void f2() { cout << "B1::f2()" << endl; }
//private:
//	string _sName1;
//};
//
//class B2 : virtual public A {
//public:
//	B2(const long& id, const char* name): _sName2(name), A(id) {
//		cout << "B2::ctor" << endl;
//	}
//	B2(const B2& b2) : A(b2) { cout << "B2::copy ctor" << endl; }
//	~B2() { cout << "B2::dtor" << endl; }
//	virtual void f3() { f1(); cout << "B2::f3()" << endl; }
//private:
//	string _sName2;
//};
//class C : public B1, public B2 {
//public:
//	C(); //you need to implement it!
//	C(const C& c); //you need to implement it!
//	~C() { cout << "C::dtor" << endl; }
//	virtual void f1() { A::f1(); cout << "C::f1()" << endl; }
//	void f3() { cout << "C::f3()" << endl; }
//
//};
//C::C() : A(234), B1(234, "B1"), B2(234, "B2") { cout << "C::ctor" << endl; }
//C::C(const C& c) : A(c), B1(c), B2(c) { cout << "C::copy ctor" << endl; }
//int main() {
//	A* pa = new B1(123456789, "Tal Ron");
//	cout << endl;
//	pa->f1();
//	cout << endl;
//	B1* pb1 = new C();
//	cout << endl;
//	pb1->f1();
//	cout << endl;
//	delete pa;
//	cout << endl;
//	delete pb1;
//	cout << endl;
//
//	return 0;
//}


//4
//class A {
//public:
//	A(const long& id): id(id) {	}
//	virtual ~A() { }
//	void f1() { cout << "A::f1()" << endl; f2(); }
//	virtual void f2() = 0;
//private:
//	long id;
//};
//
//class B1 : virtual public A {
//public:
//	B1(const long& id, const char* name): _sName1(name), A(id) {}
//	~B1() {  }
//	virtual void f1() { cout << "B1::f1()" << endl; }
//	virtual void f2() { cout << "B1::f2()" << endl; }
//private:
//	string _sName1;
//};
//class B2 : virtual public A {
//public:
//	B2(const long& id, const char* name): _sName2(name), A(id) {}
//	~B2() {  }
//	virtual void f3() { f1(); cout << "B2::f3()" << endl; }
//private:
//	string _sName2;
//};
//class C : public B1, public B2 {
//public:
//	C(); //you need to implement it!
//	C(const C& c); //you need to implement it!
//	~C() { cout << "C::dtor" << endl; }
//
//	virtual void f1() { A::f1(); cout << "C::f1()" << endl; }
//	void f3() { cout << "C::f3()" << endl; }
//
//};
//C::C() : A(234), B1(234, "B1"), B2(234, "B2") { cout << "C::ctor" << endl; }
//C::C(const C& c) : A(c), B1(c), B2(c) { cout << "C::copy ctor" << endl; }
//
////void Func1(A obj) {
////	obj.f2();
////}
//
//void Func2(A* obj) {
//	obj->f1();
//}
//
//void Func3(A& obj) {
//	obj.f1();
//}
//
//int main() {
//	A* pa = new B1(123456789, "Tal Ron");
//	Func2(pa);
//	cout << endl;
//	Func3(*pa);
//	cout << endl;
//	/*Func1(*pa);*/
//	cout << endl;
//	delete pa;
//	return 0;
//}
//
//
//
