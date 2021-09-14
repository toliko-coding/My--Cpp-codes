
#include "CArray.h"
//initialize static data member
int CArray::arrayCounter = 0;

//ctor
CArray::CArray(int size) {
	this->size = ( size > 0 ? size : 10);
	this->data = new int[this->size]; // create space for array
	arrayCounter++; //count one more object
	for (int i = 0; i < this->size; i++)
		data[i] = 0; //initialize array  (*this)[i]=0;
}
//copy ctor
CArray::CArray(const CArray& other):size(other.size) {
	this->data = new int[this->size]; // create space for array
	arrayCounter++; //count one more object
	for (int i = 0; i < this->size; i++)
		//data[i] = other.data[i]; //initialize array
	      (*this)[i]=other[i];

}

CArray& CArray::operator= (const CArray& right) {
	if (this != &right) {//check for self-assignment
		//for arrays of diferent sizes , deallocate original left side array,
		// then allocate new left side array
		if (size != right.size) {
			delete[] data;
			size = right.size;
			data = new int[size];
		}
		for (int i = 0; i < size; i++)
			data[i] = right.data[i]; //copy array into object
		   //(*this)[i] = right[i];
	}
	return *this; // enables x=y=z;     x=y;  x=x;
}

CArray::~CArray() {
	arrayCounter--; // one fewer object
	delete[] data;
} 
bool CArray::operator == (const CArray& right) const {
	if (size != right.size)
		return false;//arrays of different sizes
	for (int i = 0; i < size; i++)
		if (data[i] != right.data[i])
			return false;//arrays are not equals
	return true;//arrays are  equal
}

ostream& operator << (ostream& out, const CArray& obj) {
	int i;
	for ( i = 0; i < obj.size; i++) {
		out << setw(10) << obj.data[i]; //out << setw(10) << obj[i]; 

		if ((i + 1) % 4 == 0) // 4 numbers per row of output
			out << endl;
	}
	
	out << endl;
	return out;// enables cout<<x<<y<<z;
}
istream& operator >> (istream& in, CArray& obj) {
	cout << " Enter a data :";
	for (int i = 0; i < obj.size; i++)
		in >> obj.data[i]; //in >> obj[i];  
	return in; // enables cout>>x>>y>>z;
}
//overloaded subscript operator for const Arrays 
//const reference return creates an rvalue
const int& CArray::operator [] (int index) const {
	if (index < 0 || index >= size) {
		cout << "\n Error : index " << index << " out of range " << endl;
		exit(1);
	}
	else
		return data[index]; // int x=ob[1]; cout<<ob[1];

}
//overloaded subscript operator for non-const Arrays 
//reference return creates an lvalue
 int& CArray::operator [] (int index) {
	if (index < 0 || index >= size) {
		cout << "\n Error : index " << index << " out of range " << endl;
		exit(1);
	}
	else
		return data[index]; //obj[1]=10; 

}