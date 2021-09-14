#include <iostream>
#include <string>
using namespace std;
#pragma warning( disable : 4290 )
void Calculator(const double , const double ,const char ) throw(const char*, const char);
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

void Calculator(const double Oper1, const double Oper2,	const char Symbol) throw(const char*, const char)
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