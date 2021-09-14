
#include "TemplFunction.h"

int main() {
	int i = 5, j = 6, k;
	long l = 10, m = 5, n;
	k = GetMax(i, j);//GetMax<int>(i, j);
	n = GetMax(l, m);//GetMax<long>(l, m);
	cout << k << endl;
	cout << n << endl;
	//This would not be correct, since our GetMax function template expects two arguments of the same type, 
	//and in this call to it we use objects of two different types.
	//cout << GetMax(j, m) << endl;
	cout << GetMax<int>(j, m) << endl;
	cout << GetMax((long)j, m) << endl;
	return 0;
}