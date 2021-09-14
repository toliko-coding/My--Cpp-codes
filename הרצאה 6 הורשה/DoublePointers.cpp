#include <iostream>
using namespace std;

class CPoint {
	int x, y;
public:
	CPoint(int x = 0, int y = 0) :x(x), y(y) {}
	void Print()const
	{
		cout << '(' << this->x << ',' << this->y << ')' << endl;
	}
	
};

class CPolygon {
	CPoint** arr;
	int count;
public:
	CPolygon() :arr(nullptr), count(0) {}
	~CPolygon() {
		if (arr)
			for(int i=0;i<count;i++)
				delete arr[i];
			delete[] arr;
	}
	void Print()const
	{
		if (count) {
			for (int i = 0; i < count; i++)
				arr[i]->Print();
		}
		else
			cout << " Empty !"<<endl;
	}
	CPolygon& operator+=(const CPoint& add) {
		int i;
		CPoint** temp = new CPoint*[++count];
		for ( i = 0; i < count - 1; i++)
			temp[i] = arr[i];
		temp[i] = new CPoint(add);
		if (arr)
			delete[] arr;
		arr = temp;
		return *this;
	}
	void addPoint() {
		int x, y, i;
		cout << " Enter point's coordinates (x y) ";
		cin >> x >> y;
		CPoint* ptrPoint = new CPoint(x,y);
		CPoint** temp = new CPoint*[++count];
		for (i = 0; i < count - 1; i++)
			temp[i] = arr[i];
		temp[i] = ptrPoint;
		if (arr)
			delete[] arr;
		arr = temp;
		
	}

};

/*
int main()
{
	CPolygon pol;
	CPoint p1(1, 2), p2(3, 4);
	pol.Print();
	pol += p1;
	pol += p2;
	pol.addPoint();
	pol.Print();
	return 0;
}
*/
