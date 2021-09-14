#pragma once
#include <cstring> // string.h
#include "Student.h"
#include <iostream>
using namespace std;


//ctr / dtr
Student::Student() :name("unknown"), ID("000"), Gender(' '), age(0), myCourses(nullptr), numOfCourses(0)
{

	cout << endl << "Defualt Student Created !" << endl;
}

Student::Student(const Student& other)
{
	name = other.name;
	ID = other.ID;
	Gender = other.Gender;
	age = other.age;
	numOfCourses = other.numOfCourses;

	myCourses = new Course* [numOfCourses];
	for (int i = 0; i < numOfCourses  ; i++)
	{
		myCourses[i] = new Course;
	}

	for (int i = 0; i < numOfCourses ; i++)
	{
		*myCourses[i] = *other.myCourses[i];
	}

}

Student::Student(string _name, string _ID, char _gender, int _age, Course** _courses, int _numofCourses):
	name(_name) , ID(_ID) , Gender(_gender) , age(_age) , myCourses(_courses) , numOfCourses(_numofCourses)
{
	cout << endl << " Student(///) Created !" << endl;
}

Student::~Student()
{
	if (myCourses != nullptr)
	{
		delete[] myCourses;
		cout << "~Student (myCourse = true)" << endl;
	}
	else
	{
		cout << "~Student (myCourse = nullptr)" << endl;
	}
}


// get
string Student::Getname() const
{
	return name;
}

string Student::GetID() const
{
	return ID;
}

char Student::GetGender() const
{
	return Gender;
}

int Student::Getage() const
{
	return age;
}

int Student::GetNumOfCourses() const
{
	return numOfCourses;
}

Course Student::GetCourse(int index) const
{
	return *myCourses[index];
}

//set

void Student::Setname(string _name)
{
	name = _name;
}

void Student::SetID(string _ID)
{
	ID = _ID;
}

void Student::SetGender(char _Gender)
{
	Gender = _Gender;
}

void Student::SetAge(int _age)
{
	age = _age;
}

void Student::SetNumOfCourses(int _newnum)
{
	numOfCourses = _newnum;
}

void Student::numOfCoursesPP()
{
	SetNumOfCourses(GetNumOfCourses() + 1);
}

void Student::AddCourse( Course* other)
{
	numOfCourses++;
	

	Course** temp = new Course* [numOfCourses];
	int i = 0;
	for ( i=0; i < numOfCourses - 1; i++)
	{
		temp[i] = myCourses[i];
	}
	temp[i] = other;
	
	if (myCourses)
		delete[] myCourses;

	myCourses = temp;

	cout << "Course have been added to myCourses" << endl;


	
}


//OPERATORS !

Student& Student::operator=(const Student& other)
{
	name = other.name;
	ID = other.ID;
	Gender = other.Gender;
	age = other.age;
	numOfCourses = other.numOfCourses;

	if (other.myCourses)
	{
		myCourses = new Course * [numOfCourses];
		int i = 0;
		for (i = 0; i < numOfCourses; i++)
		{
			new Course;
			*myCourses[i] = *other.myCourses[i];
		}
	}
	// TODO: insert return statement here
	return *this;
}

bool Student::operator==(const Student& other)
{
	return ID == other.GetID();
}

Student& Student::operator+=( Course& course)
{

	course += *this;

	return *this;
}

//cin / cout

ostream& operator<<(ostream& out, Student& obj)
{
	cout << "Name :" << obj.Getname() << endl;
	cout << "ID : " << obj.GetID() << endl;
	cout << "Gender : " << obj.GetGender() << endl;
	cout << "Age : " << obj.Getage() << endl;

	if (obj.myCourses)
	{
		cout << obj.Getname() << " List of Courses: Printing... " << endl;
		for (int i = 0; i < obj.numOfCourses; i++)
		{
			cout << i+1 << endl;
			obj.myCourses[i]->PrintCourseInfo();
			
			cout << "Grade in this Course :" << obj.myCourses[i]->GetGradeById(obj.GetID());
			
			cout << endl;
		}
	}
	else
		cout << "The Student is not registered to any Courses " << endl;
	// TODO: insert return statement here
	return out;
}

istream& operator>>(istream& in, Student& obj)
{
	cout << " Please Enter Student's name : " << endl;
	string tempname;
	cin >> tempname;
	obj.Setname(tempname);

	cout << endl;

	cout << " Please Enter ID :" << endl;
	string tempID;
	cin >> tempID;
	obj.SetID(tempID);

	cout << endl;

	cout << "Please Enter Student Gender < F-female / M-male" << endl;
	char tempgender;
	cin >> tempgender;
	obj.SetGender(tempgender);

	cout << endl;

	cout << "Please Enter Student Age :" << endl;
	int tempage;
	cin >> tempage;
	obj.SetAge(tempage);

		
	
	// TODO: insert return statement here
	return in;
}
