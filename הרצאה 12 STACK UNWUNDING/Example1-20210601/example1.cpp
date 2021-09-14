// Example 1_1
#include <iostream> 
using namespace std;

float Div(int a, int b) {
	if (b == 0)
		throw "Dividing by Zero";
	else if (b < 0)
		throw 0;
	else
		return (float)a / b;
}

int main() {
	
	try {
		float r1 = Div(3, 4);
		cout << "r1 = " << r1 << endl;
		float r2 = Div(4, 0);
		cout << "r2 = " << r2 << endl;		
		float r3 = Div(2, -5);
		cout << "r3 = " << r3 << endl;
	}
	catch (const char* msg) { // char* msg -----> catch(...)
		cout << "An error occurred!!!!!" << endl;
		cout << msg << endl;
	}
	catch (int num) {
		cout << "An error occurred!!!!!" << endl;
		cout << "the number " << num <<
			" was caught." << endl;
	}
	catch (...) {
		cout << "An unknown error occurred!!" << endl;
	} // Comment!!!!
	//always get here:
	cout << " The end !" << endl;
	return 0;
}


// Example 1_2

 //A simple exception-handling example that checks for
 //divide-by-zero exceptions.
//#include "DivideByZeroException.h" // DivideByZeroException class 
//
//
////// perform division and throw DivideByZeroException object if 
////// divide-by-zero exception occurs
//double Quotient( int numerator, int denominator )
//{
//   // throw DivideByZeroException if trying to divide by zero
//   if ( denominator == 0 )
//      throw DivideByZeroException(); // terminate function
//
//   // return division result
//   return double( numerator ) / denominator;
//} // end function quotient
//
//int main()
//{
//	
//   int number1; //  numerator
//   int number2; //  denominator
//   double result; // result of division
//
//   cout << "Enter two integers (end-of-file to end): ";
//
//   // enable user to enter two integers to divide
//   while ( cin >> number1 >> number2 ) // CRTL+Z for exit
//   {
//      // try block contains code that might throw exception
//      // and code that should not execute if an exception occurs
//      try 
//      {
//         result = Quotient( number1, number2 );
//         cout << "The quotient is: " << result << endl;
//      } // end try
//      catch ( DivideByZeroException & divideByZeroException )
//      {
//         cout << "Exception occurred: " 
//            << divideByZeroException.what() << endl;
//      } // end catch
//
//      cout << "\nEnter two integers (end-of-file to end): ";
//   } // end while
//
//   cout << endl;
//} // end main