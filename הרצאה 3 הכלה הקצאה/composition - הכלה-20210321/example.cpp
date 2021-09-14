// example.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "CLine.h"

int main()
{
	
	//only CPoints
	//cout << " ------------------CPoint objects---------------------- " << endl;
 //   CPoint p1, p2(10), p3(2, 3);// This objects are stored in the Stack
	//p1.Print();
	//p2.Print();
	//p3.Print();

	//cout << p2.getX() << ' ' << p3.getY() << endl;
	//CPoint *ptrPoint = new CPoint(3, 4); // This object is stored in the Heap, operator new activates to  costructor ( ctor)
	//ptrPoint->Print();

	//delete ptrPoint; // operator delete activates to  destructor ( dtor)
	//cout << " -------------------CPoint objects-------------------------- " << endl<<endl;

	cout << " -------------------CLine objects--------------------------- " << endl;
	//CLines including CPoints
	CLine myLine(1, 2, 3, 4), *ptrLine;
	ptrLine = new CLine(10, 20, 30);
	myLine.Print();
	ptrLine->Print();

	delete ptrLine;

	cout << " -------------------CLine objects------------------------------- " << endl << endl;
	cout << " -------------------End of program------------------------------- " << endl << endl;
}

