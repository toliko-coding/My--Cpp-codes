#pragma once

#ifndef STUDENT
#define STUDENT
#include <string.h>
#include "Course.h"
using namespace std;


class Course;

class Student {
private:
	string name;
	string ID;
	char Gender; // F or M
	int age;
	Course** myCourses;
	int numOfCourses;

public:
	//Ctr / Dtr /c.ctr
	Student();
	Student(const Student& other);
	Student(string _name, string _ID, char _gender, int _age, Course** _courses, int _numofCourses);
	~Student();

	//get
	string Getname() const;
	string GetID() const;
	char GetGender() const;
	int Getage() const;
	int GetNumOfCourses() const;
	Course GetCourse(int index) const;

	//set
	void Setname(string _name);
	void SetID(string _ID);
	void SetGender(char _Gender);
	void SetAge(int _age);
	void SetNumOfCourses(int _newnum);
	void numOfCoursesPP();
	void AddCourse( Course* other);

	//operators
	Student& operator = (const Student& other);
	bool operator == (const Student& other);
	Student& operator += ( Course& course);

	//cin  // cout
	friend ostream& operator << (ostream& out, Student& obj);
	friend istream& operator >> (istream& in, Student& obj);

	//friend with class
	friend Course;
};


#endif // !STUDENT