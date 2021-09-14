#include <iostream>
using namespace std;
class CPoint {
	int x, y;
public:
	CPoint(int = 0, int = 0);
	~CPoint();
	void Print();
};
CPoint::CPoint(int _x, int _y) :x(_x), y(_y) {
	
}
CPoint::~CPoint() {
	cout << endl << "I'm dtor ";
	Print();
	cout << this;
}
void CPoint::Print() {
	cout << '('<< x << ',' << y << ')' << endl;
}
int main(){
	CPoint p1 , p2(2), p3(5, 6);
	CPoint* ptr = new CPoint(6);
	
	ptr->Print();

	p1.Print();
	p2.Print();
	p3.Print();
	
	cout << " End program !" << endl;
	
	return 0;
}

