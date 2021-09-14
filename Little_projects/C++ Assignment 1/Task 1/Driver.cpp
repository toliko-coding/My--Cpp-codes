#include <iostream>
#include<string.h>
#include <iomanip>


/*Assignment: 1
Author: Anatoli Kot, ID: 324413756 */

using namespace std;

#include "fNum.h"

int main()
{
	//Constructors
	class fNum num1;
	class fNum num2(1, 2);
	class fNum num3('3', '4');

	//print methods
	cout << "num1 is" << endl;
	num1.printfNum();

	cout << "num2 is" << endl;
	num2.printfNum();

	cout << "num3 is" << endl;
	num3.printfNum();

	cout << endl;

	//Convert to INT method 
	cout << "num1 int is :" << num1.getInt() << endl;
	cout << "num2 int is :" << num2.getInt() << endl;
	cout << "num3 int is :" << num3.getInt() << endl;

	cout << endl;

	//change char values method

	num1.setNum(99);
	num2.setNum(num2.getInt() + 1);
	num3.setNum(num3.getInt() + 1);

	cout << endl;

	//print methods
	cout << "num1 is" << endl;
	num1.printfNum();

	cout << "num2 is" << endl;
	num2.printfNum();

	cout << "num3 is" << endl;
	num3.printfNum();


	cout << endl;





	

	return 0;
}