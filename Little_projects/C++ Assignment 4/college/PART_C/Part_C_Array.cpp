#include <iostream>
#include < string>

#include "Array.h"

using namespace std;

int main()
{
	Array<int> int1;
	Array<int> int2;
	Array<float> float1;
	Array<float> float2;

	int1 += 1;
	int1 += 2;
	int1 += 3;
	int1 += 4;
	int2 += 5;
	int2 += 6;
	int2 += 7;
	int2 += 8;

	float1 += 1.1;
	float1 += 1.2;
	float1 += 1.3;
	float1 += 1.4;
	float2 += 1.5;
	float2 += 1.6;
	float2 += 1.7;
	float2 += 1.8;

	cout << "index of int num = 3 : "  << int1[3];
	cout << "index of float num = 3 : "  << float1[1.3];


	int1.printArr();
	float1.printArr();

	int1 -= 3;
	float1 -= 1.3;

	
	cout << "Delteting 3 and 1.3" << endl;
	int1.printArr();
	float1.printArr();

	

	

	return 0;
}