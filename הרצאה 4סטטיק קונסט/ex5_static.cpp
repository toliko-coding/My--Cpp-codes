#include <iostream>
using namespace std;
class Point {
	int x, y;
	static int counter; //Count how many objects have created
	static int maxY; // The maximum Y between all objects
public:
	Point(int = 0, int = maxY);//ctor
	Point(const Point&);// copy ctor
	~Point();//dtor
	void Print() const;
	static int getCounter();
};
Point::Point(int x, int y) :x(x), y(y) {
	if (y > maxY)
		maxY = y;
	counter++; 
}
Point::Point(const Point& other) : x(other.x), y(other.y) { counter++; }

Point::~Point() { counter--; }
void Point::Print()const {
	cout << "("<<this->x <<","<< this->y <<")"
		<<" counter:"<<  counter<<" maxY :"<<maxY<< endl;
}

int Point::getCounter() {	return counter;}

//Initialization of static variables
int Point::counter = 0; 
int Point::maxY = 0;
int main()
{
	cout << "The amount of objects :"<<Point::getCounter() << endl;
	Point p1(1), p2(4, 3) ,arr[3];
	cout << "The amount of objects :" << Point::getCounter() << endl;
	cout << "The amount of objects :" << p1.getCounter() << endl;
	p1.Print();
	Point * ptr = new Point();
	cout << "The amount of objects :" << ptr->getCounter() << endl;
	ptr->Print();
	delete ptr;
	cout << "The amount of objects :" << Point::getCounter() << endl;
	

}

