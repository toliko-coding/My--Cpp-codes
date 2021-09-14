#pragma once
#include <iostream>
#include<string.h>

template <class T>
bool Symmetric( T* arr , int size)
{
	
	T* temp = new T[size];

	for (int i = 0; i < size; i++)
	{
		temp[i] = arr[i];
	}

	int i = 0;
	int j = size - 1;
	bool solution = true;

	while (i < j)
	{
		if (arr[i] != temp[j])
			solution = false;

		i++;
		j--;
	}
	
	
	return solution;
}
