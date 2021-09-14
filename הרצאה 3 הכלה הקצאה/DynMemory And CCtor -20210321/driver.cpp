#include <iostream>
using namespace std;
#include "DynArr.h"
void stam( DynArray& obj) {
	cout << "start  stam \n";
	obj.Print();
	cout << "end  stam ";
}
//DynArray stam() {
//	cout << "start  stam \n";
//	DynArray obj;
//	cout << "end  stam ";
//	return obj;
//}
int main()
{
	int arr[] = { 4,7,8,9 };
	DynArray ar1, ar2(arr, sizeof(arr) / sizeof(int)), ar3(ar2);
	ar1.Print();
	ar2.Print();
	ar3.Print();
	stam(ar2);
	/*stam().Print();*/
	
	return 0;
}