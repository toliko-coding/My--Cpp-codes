
#include "Point.h"

int main()
{
	CPoint p1, p2(3, 4), p3(p2);// p3=p2;
	if (p1 != p2) // p1.operator!=(p2)
		cout << " Not equal ";
	else
		cout << " Equal ";
	cout << endl;
	if (p2==p3) // p2.operator==(p3)    if(p2.Equal(p3))
		cout << " Equal ";
	else
		cout << "  Not equal ";
	cout <<endl<< " += "<<endl;
	p2.Print();
	p3.Print();
	p2 += p3;// p2.operator+=(p3)
	p2.Print();
	p3.Print();
	cout << " + " << endl;
	p1.Print();
	p1 = p2 + p3; // p1.operator = (p2.operator+(p3))
	p1.Print();
	cout << "  ++p1 " << endl;
	p3 = ++p1;
	p3.Print();
	p1.Print();
	cout << "  p1++ " << endl;
	p3 = p1++;
	p3.Print();
	p1.Print();
	cout << "  =   <<" << endl;
	cout << "p1 = " << p1 << "p3 = " << p3 << endl;// cout<<p1;    operator<<(cout,p1);   cout<<p1<<p2<<p3;
	p1 = p3;
	cout << "p1 = " << p1 << "p3 = " << p3 << endl;
	cout << "  >>  " << endl;
	cin >> p1 >> p3;// cin>>p1;  operator>>(cin,p1);
	cout << "p1 = " << p1 << "p3 = " << p3 << endl;
	return 0;

}

