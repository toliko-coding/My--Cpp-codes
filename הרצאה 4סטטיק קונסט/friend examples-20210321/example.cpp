
#include "CLine.h"

int main()
{
	CLine myLine(1, 2, 3, 4);
	myLine.Print();
	myLine.Shrink();
	myLine.Print();
	return 0;
}

