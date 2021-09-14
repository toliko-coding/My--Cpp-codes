#include "CLine.h"
CLine::CLine(int x1, int y1, int x2, int y2) :start(x1, y1), end(x2, y2) { }

CLine::~CLine() {
	cout << "---------------------------------------------------" << endl;
	cout << "I'm dtor , this is the data of the CLine destroyed object :\n";
	Print();
	cout << "---------------------------------------------------" << endl<<endl;
}
void CLine::Print() {
	cout << " CLine's data :\nstart point : \n";
	start.Print();
	cout << "end point : \n ";
	end.Print();
	cout<< endl;
}