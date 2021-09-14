#include <iostream>
using namespace std;

class Point {
	int x, y;
public:
	Point(int = 0, int = 0);
	bool Equal(const Point&)const;
	void Print()const;
	int getX()const { return x; }
	void setX(int);

};
Point::Point(int x, int y) :x(x), y(y) {}

void Point::Print()const {
	cout << this->x << ' ' << this->y << endl;
}
void Point::setX(int x) {
	this->x = x;

}
bool Point::Equal(const Point& sec)const {
	// this->x=20 ; error!
	//sec.x = 20 ; error !
	//sec.setX(55); error !   - sec.Print(); - OK
	return this->x == sec.x && this->y == sec.y;

}
int main()
{
	Point p1(1, 2), p2(p1); //non-const obects
	if ( p1.Equal(p2))
		cout << "The objects p1 and p2  are the same ";
	else
		cout << " The objects p1 and p2 are not the same ";
	cout << endl;
	p1.setX(100);
	p1.Print();
	p2.Print();

	const Point p3(5,6);//const object
	p3.Print();

	if (p1.Equal(p3))
		cout << "The objects p1 and p3  are the same ";
	else
		cout << " The objects p1 and p3 are not the same ";
	cout << endl;
	//p3.setX(55); error
}
