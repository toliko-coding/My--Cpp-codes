#pragma once
// function template
#include <iostream>
using namespace std;

//template <class T>
//T GetMax(T a, T b) {
//	T result;
//	result = (a > b) ? a : b;
//	return result; // return (a > b) ? a : b;
//}
template <class T>
T GetMax(T a, T b) {
	if(a > b) 
		return a ;
	else return b;
	
}
