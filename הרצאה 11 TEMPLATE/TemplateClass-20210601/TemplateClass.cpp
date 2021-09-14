#include "Array.h"



int main() {
	Array<int, long> inumbers(20);
	Array<float, float> fnumbers(20);
	
	for (int i = 0; i < 10; i++)
		inumbers.AddValue(i);

	inumbers.Print();
	cout << " Sum of elements : " << inumbers.Sum()
		<< " Average : " << inumbers.Average()<<endl;

	for (int i = 0; i < 10; i++)
		fnumbers.AddValue(i+100);

	fnumbers.Print();
	cout << " Sum of elements : " << fnumbers.Sum()
		<< " Average : " << fnumbers.Average()<<endl;


	return 0;
}

