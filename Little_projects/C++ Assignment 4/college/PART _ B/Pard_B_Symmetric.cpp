#include <iostream>
#include<string.h>
#include "Symmetric.h"

using namespace std;

int main()
{
	// size = even
	int arr1[] = { 1,2,3,3,2,1 }; // Symmetric
	int arr11[] = { 1,2,3,3,2,2 }; // non Symmetric

	char arr2[] = { 'a', 'b', 'c', 'c', 'b' , 'a'}; // Symmetric
	char arr22[] = { 'a', 'b', 'c', 'x', 'b' , 'a'}; // non Symmetric

	int size = 6;
	cout << "SIZE = EVEN" << endl;
	cout << "line 10 -- >  " <<  Symmetric(arr1, size) << endl;
	cout << "line 11-- >  " <<  Symmetric(arr11, size) << endl;
	cout << "lune 13-- >  " <<  Symmetric(arr2, size) << endl;
	cout << "line 22-- >  " <<  Symmetric(arr22, size) << endl;


	//size = odd
	size = 5;
	int arr3[] = { 1,2,3,2,1 }; // Symmetric
	int arr33[] = { 1,2,3,3,2 }; // non Symmetric


	char arr4[] = { 'a', 'b', 'c', 'b', 'a'  }; //  Symmetric
	char arr44[] = { 'a', 'b', 'c', 'x', 'b'  }; // non Symmetric



	cout << "SIZE = EVEN" << endl;
	cout << "line 24 -- >  " << Symmetric(arr3, size) << endl;
	cout << "line 25 -- >  " << Symmetric(arr33, size) << endl;
	cout << "line 28 -- >  " << Symmetric(arr4, size) << endl;
	cout << "line 29 -- >  " << Symmetric(arr44, size) << endl;

}