#pragma once

#include <iostream>
#include < string>

using namespace std;

template < class T >
class Array
{
private:
	T* arr;
	int size;

public:

	//ctr , dtr
	Array();
	Array(int size);
	~Array();

	//get
	T get(int index) const;
	int getSize() const;

	//set
	void setSize(int _size);
	void add(T obj);

	//print
	void printArr() const;
	void printType() const;

	int findIndex(const T obj) const;
	T operator[](int index) const;
	int findMax() const;
	int findMin() const;
	Array& operator +=(const T other);
	Array& operator -=(const T other);
	Array& operator +(const Array<T>& other);
	bool operator ==(const Array<T>& secend);
	friend ostream& operator <<(ostream &out,const Array<T>& obj);
	


};


//ctr , dtr


template<class T>
 Array<T>::Array()
{
	arr = nullptr;
	size = 0;
	cout << typeid(T).name() << " Array is Created : default" << endl;
}

template<class T>
 Array<T>::Array(int _size)
{
	size = _size;

	arr = new T[size];

	

	cout << typeid(T).name() << " Array is Created : Builder" << endl;
}

template<class T>
Array<T>::~Array()
{
	delete[] arr;
	cout << typeid(T).name() << " is Deleted : default" << endl;

	
}


//get
template<class T>
 T Array<T>::get(int index) const
{
	return arr[index];
}

template<class T>
 int Array<T>::getSize() const
{
	return size;
}


 //set
template<class T>
 void Array<T>::setSize(int _size)
{
	 delete[] arr;
	size = _size;

	arr = new T[size];


	cout << "New size is Updated = empty Array size : " << size << endl;
}


 //add
 // RESTRICTIONS :T must suport operator =
 template<class T>
 inline void Array<T>::add(T obj)
 {
	 if (size == 0)
	 {
		 arr = new T;
		 arr[0] = obj;
		 size += 1;
		 cout << "first object added to array" << endl;
	 }
	 else
	 {
		 size += 1;
		 T* temp = new T[size];
		 int i = 0;
		 for (i ; i < size-1; i++)
		 {
			 temp[i] = arr[i];
		 }
		 temp[i] = obj;
		 delete[] arr;
		 arr = temp;
		 cout << "object Added to excisted array" << endl;
	 }
 }


 //print
 // RESTRICTIONS :T must suport operator << 
template <class T> 
void Array<T>::printArr() const                           
{
	cout << "printing Arr..." << endl;
	cout << "type : ";
	printType();

	for (int i = 0; i < size ; i++)
	{
		cout << i + 1 << " : " << arr[i] << endl;
	}
}

template<class T>
void Array<T>::printType() const
{
	cout << typeid(T).name() << endl;
}

//findIndex
// RESTRICTIONS :T must suport operator ==
template<class T>
 int Array<T>::findIndex(const T obj) const				
{
	 bool found = false;
	 int i = 0;
	 for (i; i < size; i++)
	 {
		 if (arr[i] == obj)
			 throw i;
	 }

	 string msg = "not found";
	 throw msg;
}

 
 //operator []
 // RESTRICTIONS : must suport operator =
 template<class T>
  T Array<T>::operator[](int index) const
 {
	  if (size == 0)
	  {
		  string msg = "This Array is Empty";
		  throw msg;
	  }
	  else if (index >= 0 && index <= size)
	  {
		  T temp = arr[index];
		  throw temp;
	  }
	  else if(index < 0)
	  {
		  string msg = "Index need to be positive";
			  throw msg;
	  }
	  else if(index > size)
	  {
		  string msg = "Index is biger that Array Size";
		  throw msg;
	  }
	  else
	  {
		  string msg = "Unknown";
		  throw msg;
	  }
 }


  //findMax
  // RESTRICTIONS : must suport operator >
  template<class T>
  int Array<T>::findMax() const
  {
	  if (size == 0)
	  {
		  string msg = "This Array is Emply";
		  throw msg;
	  }
	  else
	  {
		  int max = 0;
		  for (int i = 1; i < size; i++)
		  {
			  if (arr[i] > arr[i - 1])
			  {
				  max = i;
			  }
		  }
		  throw max;
	  }
  }


  //findMin
  // RESTRICTIONS : must suport operator <
  template<class T>
  inline int Array<T>::findMin() const
  {
	  if (size == 0)
	  {
		  string msg = "This Array is Emply";
		  throw msg;
	  }
	  else
	  {
		  int min = 0;
		  for (int i = 1; i < size; i++)
		  {
			  if (arr[i] < arr[i - 1])
			  {
				  min = i;
			  }
		  }
		  throw min;

	  }
  }




  //operator +=
  // RESTRICTIONS :T must suport operator =
  template<class T>
   Array<T>& Array<T>::operator+=(const T other)
  {
	   if (size == 0)
	   {
		   size = size + 1;
		   arr = new T[size];
		   arr[0] = other;
		   return *this;
	   }
	   else
	   {
		   size += 1;
		   T* temp = new T[size];
		   temp[0] = other;

		   for (int i = 0; i < size - 1; i++)
		   {
			   temp[i + 1] = arr[i];
		   }

		   delete[] arr;
		   arr = temp;
		   return *this;
	   }
  }


   //operator -=
  // RESTRICTIONS :T must suport operator ==
   template<class T>
   inline Array<T>& Array<T>::operator-=(const T other)
   {
	   int counter = 0;
	   for (int i = 0; i < size; i++)
	   {
		   if (arr[i] != other)
			   counter++;
	   }

	   if (counter == 0)
		   return *this;
	   else
	   {


		   T* temp = new T[counter];

		   int i = 0;
		   int j = 0;

		   while (i < size)
		   {
			   if (arr[i] != other)
			   {
				   temp[j] = arr[i];
				   j++;
			   }
			   i++;
		   }

		   size = counter;
		   delete[] arr;
		   arr = temp;
		   return *this;
	   }
   }


   //operator +
 // RESTRICTIONS :T must suport operator []
   template<class T>
   inline Array<T>& Array<T>::operator+(const Array<T>& other)
   {
	   int sum = getSize() + other.getSize();

	   Array<T>* temp = new Array<T>;
	   
	   int i = 0;
	   int j = 0;

	   for (i; i < size ; i++)
	   {
		   temp->add(arr[i]);
	   }
	   for (j; j < other.getSize(); j++)
	   {
		   temp->add(other.get(j));
	   }

	   cout << " Two arrays is added together" << endl;
	   

	
	   return *temp;
   }

   template<class T>
   bool Array<T> :: operator==( const Array<T>& secend)
   {
	   if (size != secend.getSize())
		   return false;

	   for (int i = 0; i < size; i++)
	   {
		   if (get(i) != secend.get(i))
			   return false;
	   }

	   return true;
   }


   //operator << 
   template <class T>
   ostream& operator<<(ostream &out,const Array<T>& obj)
   {
	   out << "wow";
	   return out;
   }
  
 




   
