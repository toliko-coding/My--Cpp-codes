#pragma once
class DynArray {
	int* data;
	int size;
public:
	DynArray();//def ctor
	DynArray(int* , int );//ctor
	DynArray(const DynArray&);//cctor
	~DynArray(); //dtor
	void CopyElements(int*, int);//coping of elements
	void Print();// printing of elements
		
};

