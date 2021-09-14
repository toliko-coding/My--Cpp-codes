#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring> // string.h

#include <string> // class string
using namespace std;
int main()
{
	/*char firstStr[50] = "This is softwareTestingHelp.com";
	char secStr[50] = "a testing platform";

	int len = strlen(firstStr);
	cout << "Length of firstStr : " << len;
	strcpy(secStr, "softwareTesting");
	cout << "\nResultant string (secStr):" << secStr;
	cout << "\nComparing firstStr and secStr :" << strcmp(firstStr, secStr);
	strcat(secStr, " for you");
	cout << "\nConcatenated secStr: " << secStr;
	cout << "\nFirst occurence of i in firststr at:" << strchr(firstStr, 'T');*/

	/* Output
	Length of firstStr: 31
	Resultant string (secStr):softwareTesting
	Comparing firstStr and secStr :-1
	Concatenated secStr: softwareTesting for you
	First occurrence of i in firststr at: s is softwareTestingHelp.com
	*/

	string str;
	cout << "Input the string\n";
	getline(cin, str);
	cout << "\nString entered is :" << str;
	int len = str.length();
	cout << "\nLength of the string str is :" << len;
	string str1 = "SoftwareTestingHelp";
	if (str == str1) //if (str.compare(str1) == 0)
	{
		cout << "\nTwo strings are equal\n";
	}
	else
	{
		cout << "\nTwo strings are not equal\n";
	}
	str1 += ".com";// str1.append(".com");
	cout << "\nNew str1 : " << str1;
	cout << "\n The second letter : " << str1[1] ;
	str.clear();
	cout << "\n\nstr new length : " << str.length();

	/*
	Input the string
	SoftwareTestingHelp

	String entered is: SoftwareTestingHelp
	Length of the string str is: 19
	Two strings are equal

	New str1: SoftwareTestingHelp.com
	The second letter : o

	str new length : 0
	*/
	return 0;

}