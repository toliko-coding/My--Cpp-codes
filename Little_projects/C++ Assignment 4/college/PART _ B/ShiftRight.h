#pragma once
#include <iostream>
#include <string>

using namespace std;


template <typename T>
T* ShiftRight(T* arr, int size , int move)
{
	T* temp = new T[size];
	for (int i = 0; i < size; i++)
	{
		temp[i] = arr[i];
	}
	
	int j;
	
	for (int i = 0; i <= move ; i++)
	{

		 j = 0;
		T first = temp[0];
		for (j ; j < size - 1; j++)
		{
			temp[j] = temp[j + 1];
		}
		temp[j] = first;

		

	}


	



	return temp;
}