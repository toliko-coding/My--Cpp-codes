#include <iostream>
using namespace std;
#include "DynArr.h"

DynArray::DynArray() :data(nullptr), size(0) {  }
DynArray::DynArray(int* d, int count) :size(count) {
	data = new int[size];
	CopyElements(d, count);
}
DynArray::~DynArray() {
	cout << "\nI'm dtor\n";
	/*Print();*/
	if (data)
		delete[] data; 
}
DynArray::DynArray(const DynArray& sec):size(sec.size) {
	cout << "\nI'm cctor\n";
	data = new int[size];
	CopyElements(sec.data, sec.size);
}
void DynArray::CopyElements(int* d, int count) {
		for (int i = 0; i < size; i++)
			data[i] = d[i];
}
void DynArray::Print() {
		if (size) {
			cout << " Total elemets : " << size << " .\n They are: \n";
			for (int i = 0; i < size; i++)
				cout << data[i] << ' ';
			cout << endl;
		}
		else
			cout << " No data . "<<endl;
		cout << endl;
}



