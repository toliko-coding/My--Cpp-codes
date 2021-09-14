#include <iostream>
#include <string>
#include "ShiftRight.h"

using namespace std;


int main()
{

	int size = 5;
	int n = 2;
	char arr[] = {'a','b','c' ,'d' ,'e'};

	char* test = new char[size];

	test = ShiftRight(arr, size , n);

	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << " : " << test[i] << endl;
	}

	delete[] test;
}
