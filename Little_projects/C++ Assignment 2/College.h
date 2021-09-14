#ifndef __COLLEGE_H
#define __COLLEGE_H

#include <iostream>
#include <string>
#include "Student.h"
#include "Course.h"
#include "Department.h"
using namespace std;

class Student;
class Course;
class Department;

class College
{
	string name;
	int codeM;
	Department** departments;
	int numOfDepartments;
	Student** students;
	int numOfStudents;
	void addDepartment();
	void addCourseToDepartment();
	void addStudentToDepartment();
	void registerStudentToCourse();
	void gradingStudentsInCourse();
	void printCourseInfo() const;
	void printStudentInfo() const;
	void printDepartmentInfo() const;
	void findStudentsWithBadAcademicStat();
	int findDepartment(int code) const;
	void addStudentToCollege(Student& newStud);
public:
	College() : departments(NULL), numOfDepartments(0), students(NULL), numOfStudents(0) {}
	College(const College&);
	~College();
	College& operator=(const College& other);
	void menu();
};

#endif