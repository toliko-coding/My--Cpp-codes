//
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//	char Number1[40], Number2[40];
//	double Operand1, Operand2, Result;
//	char Operator;
//
//	// Request two numbers from the user
//	cout << "This program allows you to perform a operation (+ - * /)  of two numbers\n";
//	cout << "To proceed, enter two numbers and operation\n";
//
//	try {
//
//		cout << "First Number:  ";
//		cin >> Number1;
//		// Examine each character of the first operand
//		// to find out if the user included a non-digit in the number
//		for (unsigned i = 0; i < strlen(Number1); i++)
//			if ((!isdigit(Number1[i])) && (Number1[i] != '.')) // Allow the period
//				throw Number1;// Send the error as a string
//		Operand1 = atof(Number1);
//
//
//		cout << "Operator:      ";
//		cin >> Operator;// Make sure the user typed a valid operator
//		if (Operator != '+' && Operator != '-' &&
//			Operator != '*' && Operator != '/')
//			throw Operator;
//
//		cout << "Second Number: ";
//		cin >> Number2;
//		// Do the same for the second number entered
//		for (unsigned j = 0; j < strlen(Number2); j++)
//			if ((!isdigit(Number2[j])) && (Number2[j] != '.')) // Allow the period
//				throw Number2;// Send the error as a string
//		Operand2 = atof(Number2);
//
//		// Find out if the denominator is 0
//		if (Operator == '/')
//			if (Operand2 == 0)
//				throw 0;
//
//		// Perform an operation based on the user's choice
//		switch (Operator)
//		{
//		case '+':
//			Result = Operand1 + Operand2;
//			break;
//
//		case '-':
//			Result = Operand1 - Operand2;
//			break;
//
//		case '*':
//			Result = Operand1 * Operand2;
//			break;
//
//		case '/':
//			Result = Operand1 / Operand2;
//			break;
//		}
//
//		// Display the result of the operation
//		cout << "\n" << Operand1 << " " << Operator << " "
//			<< Operand2 << " = " << Result << "\n\n";
//	}
//	catch (const int n)
//	{
//		cout << "\nBad Operation: Division by " << n << " not allowed\n\n";
//	}
//	catch (const char n)
//	{
//		cout << "\nOperation Error: " << n << " is not a valid operator\n\n";
//	}
//	catch (const char *BadOperand)
//	{
//		cout << "\nError: " << BadOperand << " is not a valid number\n\n";
//	}
//
//	return 0;
//}


#include <iostream>
#include <string>
using namespace std;
#pragma warning( disable : 4290 )

void Calculator(const double, const double, const char) throw(const char*, const char);
double Validate(const char *) throw(const char*);

int main()
{
	char Number1[40], Number2[40];
	double Operand1, Operand2;
	char Operator;

	cout << "This program allows you to perform an operation on two numbers\n";

	try {
		cout << "To proceed, enter\n";
		cout << "First Number: "; cin >> Number1;
		Operand1 = Validate(Number1);
		cout << "An Operator: "; cin >> Operator;
		cout << "Second Number: "; cin >> Number2;
		Operand2 = Validate(Number2);

		try {
			Calculator(Operand1, Operand2, Operator);
		}
		catch (const char * Str)
		{
			cout << "\nBad Operation: " << Str;// divide by zero
		}
	}
	catch (const char n)
	{
		cout << "\nOperation Error: " << n << " is not a valid operator";// not valid operation : %
	}
	catch (const char *BadOperand)
	{
		cout << "\nError: " << BadOperand << " is not a valid number"; // not valid operand
	}

	cout << "\n\n";
	return 0;
}

void Calculator(const double Oper1, const double Oper2, const char Symbol) throw(const char*, const char)
{
	double Value;

	if (Symbol != '+' && Symbol != '-' &&
		Symbol != '*' && Symbol != '/')
		throw Symbol;

	switch (Symbol)
	{
	case '+':
		Value = Oper1 + Oper2;
		cout << "\n" << Oper1 << " + "
			<< Oper2 << " = " << Value;
		break;

	case '-':
		Value = Oper1 - Oper2;
		cout << "\n" << Oper1 << " - "
			<< Oper2 << " = " << Value;
		break;

	case '*':
		Value = Oper1 * Oper2;
		cout << "\n" << Oper1 << " * "
			<< Oper2 << " = " << Value;
		break;

	case '/':
		if (Oper2 == 0)
			throw "Division by 0 not allowed";
		Value = Oper1 / Oper2;
		cout << "\n" << Oper1 << " / "
			<< Oper2 << " = " << Value;
		break;
	}
}

double Validate(const char* N) throw(const char*)
{
	double Valid;

	for (unsigned i = 0; i < strlen(N); i++)
		if ((!isdigit(N[i])) && (N[i] != '.'))
			throw N;

	Valid = atof(N);
	return Valid;

}

