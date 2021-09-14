//#include <iostream>
//using namespace std;
//
////template<class T>
////void DoSomething(int i) {
////	T   a, b;
////	b = a = i;
////}
//
//template<class T>
//void DoSomething(T i) {
//	T   a, b;
//	b = a = i;
//	cout << b <<' '<< a << ' '<< i;
//}
//
//int main()
//{
//	int int_value = 10;
//	DoSomething(int_value);
//   
//}

#include<iostream>
using namespace std;

//template<class X> X&  Min(X  a, X  b) {
//	return a > b ? b : a;
//}
//
//int& Min(int& a, int & b) {//rewrite of the function in the case of int:
//	cout << "int explicit function\n";
//	return a > b ? b : a;
//}
//
//
//int main() {
//	int a = 4, b = 2;
//	cout << Min(1.2, 2.3) << endl;
//	cout << Min(a, b) << endl;
//	cout << Min(3, 8); // ??
//}

#include <iostream>
using namespace std;

//template <class T> class container {
//private:
//	T element;
//public:
//	container(T arg) { element = arg; }
//	T  increase() { return ++element; }
//};
//
//template <> class container <char> {
//private:
//	char  element;
//public:
//	container(char  arg) { element = arg; }
//	char  uppercase();
//};
///*template <>*/ char container<char>::uppercase() {
//	if ((element >= 'a') && (element <= 'z'))
//		element += 'A' - 'a';
//	return element;
//}
//
//int main() {
//	container<int>  myint(7);
//	container<char>  mychar('j');
//	cout << myint.increase() << endl;
//	cout << mychar.uppercase() << endl;
//
//	return 0;
//}
//

template<class T>
T* Find(T* begin, T* end, T value) {
	while (begin != end)
		if (*begin == value)
			return begin;
		else
			begin++;

	return begin;
}

int main() {
	int array[] = { 3,2,5,7,2,8,11 };

	int* j = Find(array, array + 6, 17);
	cout << *j;
	return 0;
}


