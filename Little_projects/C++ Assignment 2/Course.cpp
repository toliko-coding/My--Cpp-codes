#pragma once
#include <cstring> // string.h
#include "Course.h"
#include <iostream>
#include "Student.h"
using namespace std;


//ctor / c.ctor / dtor
Course::Course() :name("unknown"), CourseNum(0), StudentList(nullptr), NumOfStudent(0), Grades(nullptr)
{
	
	cout << "Course Created !" << endl;
}

Course::Course(const Course& other)
{
	//only int copy
	this->name = other.name;
	this->CourseNum = other.CourseNum;
	this->NumOfStudent = other.NumOfStudent;

	//StudentList copy
	int i = 0;
	Student** Temp = new Student * [NumOfStudent];
	for (i; i < NumOfStudent ; i++)
	{
		Temp[i] = new Student;
		Temp[i] = other.StudentList[i];
	}
	this->StudentList = Temp;

	this->Grades = new int[NumOfStudent];
	for (i = 0; i < NumOfStudent ; i++)
	{
		this->Grades[i] = other.Grades[i];
	}

	

}

Course::Course(string _name, int _CourseNum, Student** _SList, int _numOfStudents, int* _grades):
	name(_name) , CourseNum(_CourseNum) , StudentList(_SList) ,NumOfStudent(_numOfStudents), Grades(_grades)
{
	cout << "Course::Course(//////) - Created !" << endl;
}

Course::~Course()
{
	if (StudentList == nullptr)
	{
		cout << "~Course (StudentList == nullptr)" << endl;
	}
	else
	{
		delete[] StudentList;
		cout << "~Course (StudentList != nullptr)" << endl;
	}

}

//operators

bool Course::operator==(const Course& other)
{
	if (CourseNum == other.CourseNum)
		return true;

	else
		return false;
}

Course& Course::operator=(const Course& other)
{
	// TODO: insert return statement here
	name = other.name;
	CourseNum = other.CourseNum;
	NumOfStudent = other.NumOfStudent;

	//Grades
	int i;
	
	if (other.Grades)
	{
		Grades = new int[NumOfStudent];
		for (i = 0; i < NumOfStudent ; i++)
		{
			this->Grades[i] = other.Grades[i];
		}
	}

	//Sudent list 
	Student** Temp = new Student * [NumOfStudent];
	for (i = 0; i < NumOfStudent ; i++)
	{
		Temp[i] = new Student;
		*Temp[i] = *other.StudentList[i];
	}
	

	delete[] StudentList;
	StudentList = Temp;

	//Department
														//**
	

	return *this;
}

Course& Course::operator+=( Student& other)
{
	// TODO: insert return statement here
	this->addStudent(&other);
	addGrade(-1);
	
	return *this;
}




//cin / cout

ostream& operator<<(ostream& out, const Course& obj)
{
	cout << "Course name: " << obj.name << endl;
	cout << "Course ID: " << obj.CourseNum << endl;
	
	if (obj.NumOfStudent == 0)
	{
		cout << "No Students in this Course Yet.." << endl;
		cout << "There is No grades given" << endl;
	}
	else
	{
		cout << "Number of students in course : " << obj.NumOfStudent << endl;

		cout << "List of Grades By Name :" << endl;

		if (obj.Grades != nullptr)
		{
			obj.PrintGrades();
		}
		else
			cout << " No Grades : EROR";
	}

	// TODO: insert return statement here
	return out;
}

istream& operator>>(istream& in, Course& obj)
{
	cout << "Enter course's name:" << endl;
	string temps;
	cin >> temps;
	obj.setname(temps);
	cout << endl << "Enter course's ID:" << endl;
	int tempid;
	cin >> tempid;
	obj.setCourseNum(tempid);
	return in;

	// TODO: insert return statement here
}



//print

void Course::printStudentds() const
{
	for (int i = 0; i < NumOfStudent; i++)
	{
		cout << *StudentList[i] << endl;
	}
}

void Course::PrintCourseInfo() const
{
	cout << "Course Information :" << endl;
	cout << "Name :" << name << endl;
	cout << "Course ID : " << CourseNum << endl;
	cout << "Number of Student in this Course :" << NumOfStudent << endl;

}

void Course::PrintGrades() const
{
	int i = 0;
	for (i; i < NumOfStudent; i++)
	{
		cout << StudentList[i]->Getname()<< "[" << StudentList[i]->GetID() << "]" << "  :  " << Grades[i] << endl;
	}
}

//SET !

void Course::setname(string _name)
{
	name = _name;
}

void Course::setCourseNum(int _num)
{
	CourseNum = _num;
}

void Course::addStudent( Student* other)
{
	NumOfStudent++;

	

	Student** temp = new Student* [NumOfStudent];

	int i = 0;
	for (i = 0; i < NumOfStudent - 1; i++)
	{
		temp[i] = StudentList[i];
	}
	temp[i] = other;

	delete[] StudentList;
	StudentList = temp;

	other->AddCourse(this);

	cout << "Student have been added to this course" << endl;

}

void Course::addGrade(int _grade)
{
	if (Grades)
	{
		int i = 0;
		int* temp;
		temp = new int[NumOfStudent];

		for ( i ; i < NumOfStudent - 1; i++)
		{
			temp[i] = Grades[i];
		}
		temp[i] = _grade;

		delete[] Grades;
		Grades = temp;
		cout << "grades updated" << endl;
		
	}
	else
	{
		Grades = new int;
		Grades[0] = _grade;
		cout << "grades Created" << endl;
	}
}

void Course::setNumofStudent(int _num)
{
	NumOfStudent = _num;
}

void Course::SetGradetoIdx(int idx, int grade)
{
	Grades[idx] = grade;
	cout << "Grade have been SET and Changed !" << endl;
}


//GET !!

string Course::getname() const
{
	return name;
}

int Course::getCourseNum() const
{
	return CourseNum;
}

Student Course::getStudent(int idx) const 
{
	return *StudentList[idx];
}

int* Course::getGrades() const
{
	return Grades;
}

int Course::getGrade(int idx) const
{
	return Grades[idx];
}

int Course::geeNumOfStudent() const
{
	return NumOfStudent;
}

int Course::GetGradeById(string id) const
{
	int i = 0;
	bool flag = false;
	for (i; i < NumOfStudent; i++)
	{
		if (StudentList[i]->GetID() == id)
		{
			flag = true;
			return Grades[i];
		}
	}
	return -1;
}
