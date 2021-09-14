// references.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void swapByValue(int, int);
void swapByPointers(int* , int* );
void swapByReference(int&, int&);

int main()
{
	int value = 10 , another=value;
	int& ref_value = value;
	ref_value = 20;
	cout << " value :" << value << "  value's address :" << &value << endl;
	cout << " another :" << another << "  another's address :" << &another << endl;
	cout << " ref_value :" << ref_value << "  ref_value's address :" << &ref_value << endl;

	//Passing the parameters to functions
	cout<<"----------------  By value -----------------------------" << endl;
	cout << " value :" << value << " another :" << another << endl;
	swapByValue(value, another);
	cout << " value :" << value << " another :" << another << endl;
	cout << "----------------  By pointer -----------------------------" << endl;
	cout << " value :" << value << " another :" << another << endl;
	swapByPointers(&value, &another);
	cout << " value :" << value << " another :" << another << endl;
	cout << "----------------  By reference --------------------------" << endl;
	cout << " value :" << value << " another :" << another << endl;
	swapByReference(value, another);
	cout << " value :" << value << " another :" << another << endl;

}

void swapByValue(int x, int y) {
	int temp = x;
	x = y;
	y = temp;
}

void swapByPointers(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

void swapByReference(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}
