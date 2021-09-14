#pragma once
#include <iostream>
using namespace std;

 template <class T, class T1>
 class Array {
	 int size;
	 int index;
	 T* data;
 public:
	 Array(int = 3);
	 T1 Sum() const ;
	 T Average() const;
	 void Print() const;
	 bool AddValue(const T&);
 };

 template <class T, class T1>
 Array<T,T1> ::Array(int size) :size(size),index(0){
	 data = new T[size];

 }

 template <class T, class T1>
 T1 Array<T, T1> ::Sum()const {
	 T1 sum = 0;
	 for(int i = 0; i < index; i++)
		sum += data[i];
	 return sum;

 }

 template <class T, class T1>
 T Array<T, T1> ::Average()const {
	 T1 sum = 0;
	 for (int i = 0; i < index; i++)
		 sum += data[i];
	 return sum/index;

 }

 template <class T, class T1>
 void Array<T, T1> ::Print()const {
	 
	 for (int i = 0; i < index; i++)
		 cout<< data[i]<<' ';
	 cout << endl;
 }

 template <class T, class T1>
 bool Array<T, T1> ::AddValue(const T& value) {
	 if (index == size)
		 return false; // array is full !
	 data[index++] = value;
	 return true;
 }
