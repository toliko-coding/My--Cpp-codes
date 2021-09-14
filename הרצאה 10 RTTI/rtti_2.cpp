#include <iostream>
#include<typeinfo>// RTTI
#include <string>
using namespace std;
typedef enum { COW=1, FROG} Choice;
class Animal {
	string name;
	/*int age;*/
public:
	Animal(string s = "unknown") :name(s) {}
	virtual void Eat() const = 0;
	virtual void WhoIAm() const  {
		cout << " I am Animal : " << typeid(*this).name() << endl;  // RTTI
	}
	virtual ~Animal() {}
	friend ostream& operator<<(ostream& os, const Animal& an) {
		an.WhoIAm();
		an.Eat();
		return os << endl;
	}
	
};


class Cow :public Animal {
	int milk; // amount of milk per day
public:
	Cow(string g="Daisy", int m=2) :Animal(g), milk(m) {}
	void Eat()const {
		cout << " Grass " << endl;
	}
	void WhoIAm() { Animal::WhoIAm();  cout <<milk << endl; } 
	int HowMilk() const { return milk; }  //////   !!!! special functions of Cow

};

//////////////////////////////////////////
class Frog :public Animal {
	float jump; // jump distance
public:
	Frog(string g = "Fradie", float m = 2.5) :Animal(g), jump(m) {}
	void Eat()const {
		cout << " Flies " << endl;
	}
	void WhoIAm() { Animal::WhoIAm();  cout << jump << endl; }
	float GetJump() const { return jump; }  //////   !!!! special functions of Frog

};
//////////////////////////////////////////////
int main() {
	Animal** Zoo;
	int size, milk, myChoice;
	string name;
	float jump;
	cout << "How many animals would you like :";
	cin >> size;
	Zoo = new Animal*[size];
	for (int i = 0; i < size; ) {
		cout << " Enter 1 - for Cow , 2 - for Frog ";
		cin >> myChoice;
		if (myChoice == COW) {
			cout << "\nEnter name and milk's amount: ";
			cin >> name >> milk;
			Zoo[i++] = new Cow(name, milk);
		}
		else if (myChoice == FROG) {
			cout << "\nEnter name and jump distance: ";
			cin >> name >> jump;
			Zoo[i++] = new Frog(name, jump);
		}
		else
			cout << " Invalid input, try again !";
	}
	// Polymorphism
	for (int i = 0; i < size; i++)
		cout << (*Zoo[i]);

	//RTTI
	int sum = 0;
	for (int i = 0; i < size; i++) {
		Cow* help;
		help = dynamic_cast<Cow*> (Zoo[i]);
		if (help) // if(help!=NULL)
			sum += help->HowMilk();
	}
	cout << "Total amount of milk :" << sum;

	//free memory
	for (int i = 0; i < size; i++)
		delete Zoo[i];
	delete[] Zoo;

	return 0;
}


//bool operator==(int find)const {
//	return age == find;
//}
//
//for (int i = 0; i < size; i++)
//	if ((*Zoo[i]) == ageFind)
//		Zoo[i]->WhoIAm();//cout<<(*Zoo[i]);