#include "CLine.h"
CLine::CLine(int x1, int y1, int x2, int y2) :start(x1, y1), end(x2, y2) {}

void CLine::Print() {
	cout << " CLine's data :\nstart point : \n";
	start.Print();
	cout << "end point : \n ";
	end.Print();
	cout<< endl;
}

void CLine::Shrink() {
	start.x = end.x; start.y = end.y;
	/*start.setX(end.getX());
	start.setY(end.getY());*/
}