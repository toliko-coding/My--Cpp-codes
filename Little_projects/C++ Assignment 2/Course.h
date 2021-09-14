#ifndef COURSE
#define COURSE


#pragma once
#include <cstring> // string.h
#include <iostream>
#include "Student.h"

using namespace std;

class Student;


class Course {

private:
	string name;
	int CourseNum;
	Student** StudentList;
	int NumOfStudent;
	int* Grades;

public:
	//print
	void printStudentds() const;
	void PrintCourseInfo() const;
	void PrintGrades() const;

	//set
	void setname(string _name);
	void setCourseNum(int _num);
	void addStudent( Student* other);
	void addGrade(int _grade);
	void setNumofStudent(int _num);
	void SetGradetoIdx(int idx, int grade);
	

	//get
	string getname() const;
	int getCourseNum() const;
	Student getStudent(int idx) const;
	int* getGrades() const;
	int getGrade(int idx) const;
	int geeNumOfStudent() const;
	int GetGradeById(string id) const;

	//ctr / dtr
	Course();
	Course(const Course& other);
	Course(string _name, int _CourseNum, Student** _SList, int _numOfStudents, int* _grades);
	~Course();

	//Operators :
	bool operator==(const Course& other);
	Course& operator=(const Course& other);
	Course& operator+=( Student& other);
	
	//cin / cout

	friend ostream& operator << (ostream& out, const Course& obj);
	friend istream& operator >> (istream& in, Course& obj);

	friend Student;



};



#endif // !COURSE
