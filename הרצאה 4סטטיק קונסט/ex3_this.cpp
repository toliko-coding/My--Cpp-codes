
#include <iostream>
using namespace std;

class Point {
	int x, y;
public:
	Point(int = 0, int = 0);
	~Point() { cout << "  I'm dtor!"; }
	void Print();
	Point& GreaterX(Point& ); 
	Point& SetX(int);
	void SetY(int);
	
};
Point::Point(int x, int y) :x(x), y(y) {}

void Point::Print() {
	cout << this->x << ' ' << this->y << endl;
}
Point& Point::GreaterX(Point& second) {
	/*The function accepts pointer this(active object)
	and a parameter-object and returns an object(!) that has a larger X*/
	if (x > second.x)
		return *this;
	else
		return second;
}
Point& Point::SetX(int x) {
	/*Updating current object and returning reference to it*/
	this->x = x; //Distinguish between a variable of the object and a variable that is a parameter passed to a function	
	return *this;
}
void Point::SetY(int y) {
	/*Just updates a current object and returns nothing*/
	this->y = y;
}
int main()
{
	Point p1(1, 2), p2(4, 3);
	Point p3 = p1.GreaterX(p2);
	p3.Print();
	
	p3.SetY(55); 
	p3.Print();
	
	p3.SetX(44).Print(); 

    std::cout << " End !\n";
}

