#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class CArray {
	int size;//size of array
	int* data;//pointer to first element of array
	static int arrayCounter;//number of arrays instantiated
public:
	/* Gifts :
	CArray(){}
	~CArray(){}
	CArray(const CArray& other):size(other.size),data(other.data){}
	CArray& operator= (const CArray& other){
		size=other.size;
		data=other.data;
		return *this;    //enables x=y=z;
	}
	*/
	CArray(int = 10);//ctor+def ctor
	CArray(const CArray& );//cctor
	~CArray();//dtor
	CArray& operator= (const CArray& );
	bool operator == (const CArray&) const;
	//input / output
	friend ostream& operator << (ostream&, const CArray&);
	friend istream& operator >> (istream&, CArray&);
	// subscript operator
	const int& operator [] (int)const ;
	 int& operator [] (int);
	static int getarrayCounter() { return arrayCounter; } // return number of arrays instantiated
};

