#include <iostream>
#include<typeinfo>// RTTI
#include <string>
using namespace std;

class Animal {
	string name;
public:
	Animal(string s = "unknown") :name(s) {}
	virtual void Print()const;
	friend ostream& operator<<(ostream&, const Animal&);
	virtual void Eat() = 0;

};
void Animal::Print()const
{
	cout << " Animal ::Print  : My name is " << name << endl;
}
// operator << for Animals   ///////////////////
ostream& operator<<(ostream& os, const Animal& a)
{
	os << typeid(a).name() << endl;
	a.Print();  // call to virtual function !!
	return os << endl;
}
//////////////////////////////////////////////

class Mammal :public Animal {
	int legs;
public:
	Mammal(string g, int leg) :Animal(g), legs(leg) {}
	void Print()const;
	void Milk() { cout << " I'm breastfeeding my children with my milk " << endl; } //////   !!!! special functions of Mammals

};
void Mammal::Print()const
{
	Animal::Print(); cout << endl << " Mammal ::Print  : I have " << legs << " legs " << endl;
}
//////////////////////////////////////////
class Dog :public Mammal {
public:
	Dog(string n, int le) :Mammal(n, le) {}
	virtual void Print()const;
	void Eat() { cout << "I like eating Dogli " << endl; }
};
void Dog::Print()const
{
	cout << " Dog::Print " << " I am a dog : "; Mammal::Print();
}
//////////////////////////////////////////////
class Cat :public Mammal {
public:
	Cat(string n, int le) :Mammal(n, le) {}
	virtual void Print()const;
	void Eat() { cout << " I like eating Kitty  Cat " << endl; }
};
void Cat::Print()const
{
	cout << " Cat::Print " << " I am a cat : "; Mammal::Print();
}
//////////////////////////////////////////////
class Birds :public  Animal {
	bool predator;
public:
	Birds(string g, bool pre) :Animal(g), predator(pre) {}
	void Print()const;
};
void Birds::Print()const
{
	Animal::Print();
	if (predator)
		cout << " predator ";
	else
		cout << " no predator ";
	cout << endl;
}
/////////////////////////////////////////////
class Eagle :public Birds {
public:
	Eagle(string n) :Birds(n, true) {}
	void Print()const;
	void Eat() { cout << " I like eating small birds and insects "; }

};
void Eagle::Print()const
{
	cout << " Eagle::Print " << " I am an eagle : "; Birds::Print();
}
///////////////////////////////////////////
void Tipeid(Animal* ptr)
{
	cout << endl << " Tipeid " << endl;
	if (typeid(*ptr) == typeid(Mammal))
		((Mammal*)(ptr))->Milk(); //bad style!!!
}
void DynamicCast(Animal* ptr)
{
	cout << endl << " DynamicCast " << endl;
	Mammal* help = dynamic_cast<Mammal*>(ptr);
	if (help)
		help->Milk();
}

int main()
{
	Animal* ptr[3];
	// Upcasting
	ptr[0] = new Cat("cat1", 4);
	ptr[1] = new Eagle("eagl1");
	ptr[2] = new Dog("dog1", 4);
	// Polymorpthism +RTTI
	for (int i = 0; i < 3; i++)
	{
		cout << " # " << i + 1 << endl;
		Tipeid(ptr[i]);
		DynamicCast(ptr[i]);
		cout << " Informatiom about myself : " <<  endl;
		cout << (*ptr[i]);
		cout << " What do I eat : " << endl;
		ptr[i]->Eat();
		delete ptr[i];
		cout << endl << " ---------------------" << endl;
	}
}


