
#include <iostream>
using namespace std;
#pragma warning( disable : 4290 )
void function1() throw (int) { //this function throws exception
	cout << "\n Entering into function 1";
	throw 100;
	cout << "\n Exiting function 1";
}

void function2() throw (int) { //This function calls function 1
	cout << "\n Entering into function 2";
	function1();
	cout << "\n Exiting function 2";
}

void function3() { //function to call function2, and handle 	exception thrown by function1
		cout << "\n Entering function 3 ";
	try {
		function2(); //try to execute function 2
	}
	catch (int i) {
		cout << "\n Caught Exception: " << i;
	}
	cout << "\n Exiting function 3";
}

int main() {
	function3();
	return 0;
}