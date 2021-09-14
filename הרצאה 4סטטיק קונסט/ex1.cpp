#include <iostream>
using namespace std;
class Point {
	int x, y;
public:
	
	Point(int =0, int =0); // ctor
	void Print();
	void SetXY(int, int);
};
Point::Point(int X, int Y) :x(X), y(Y) {}
void Point::Print() {
	cout << x << ' ' << y << endl;
}
void Point::SetXY(int X, int Y) {
	x = X;
	y = Y;
}
int main()
{
	cout << " Array of objects------\n";
	Point p1[2];// { {1, 2}, { 3,4 } };
	for (int i = 0; i < 2; i++)
		p1[i].Print();
	cout << "Dynamic Array of objects------\n";
	int size = 3;
	Point* p2 = new Point[size];// { {1, 2}, { 3,4 }, { 5,6 } };
	for (int i = 0; i < size; i++) {
		p2[i].SetXY(i,i+2);
		p2[i].Print();
	}
	delete[] p2;
	cout << "Array of pointers to objects------\n";
	Point** p3 = new Point*[size];
	for (int i = 0; i < size; i++) {
		p3[i] = new Point(i, i * 10);
		p3[i]->Print();
	}
	for (int i = 0; i < size; i++)
		delete p3[i];
	delete[] p3;
		

}

