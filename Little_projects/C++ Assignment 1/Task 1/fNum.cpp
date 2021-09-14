#include "fNum.h"
#include <string.h>
#include <iomanip>



/*Assignment: 1
Author: Anatoli Kot, ID: 324413756 */





//------ Constructors !! -------------

//char Constructor
fNum::fNum(char slNum, char srNum) :lNum(slNum), rNum(srNum) {}

//int Constructor
fNum::fNum(int _lNum, int _rNum)
{
	
	lNum = '0' + _lNum;
	rNum = '0' + _rNum;
	

}


//Defualt Constructor
fNum::fNum() : fNum(0, 0) {}







// ------METHODS !! --------------
//print method
void fNum::printfNum()
{
	cout << "lNum = " << lNum <<endl;
	cout << "rNum = " << rNum << endl;
	cout << "Full Number  = " << lNum << rNum << endl;
	cout << endl;

}

//return int value of the object
int fNum::getInt()
{
	int num = (lNum - '0')*10 + (rNum - '0');

	return num;
}

//resive int and set / change the char value of the object 
void fNum::setNum(int num)
{
	int l, r;
	r = num % 10;
	l = num / 10;

	lNum = '0' + l;
	rNum = '0' + r;

	cout << "Char value have been changed .." << endl;

}