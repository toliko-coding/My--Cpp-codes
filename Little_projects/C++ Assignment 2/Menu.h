#ifndef MENU
#define MENU
#include <string.h>
#include "Course.h"
#include "Student.h"
using namespace std;

class Course;
class Student;

class Menu {
private:
	Course** AllCourses;
	int NumofAllCourses;
	Student** AllStudents;
	int NumOfallStudents;

public:
	//ctor / dtor / c.ctr
	Menu();
	Menu(Course** _allcourses, int _numofallcourses, Student** _allstudents, int _numofallstudents);
	~Menu();

	//set
	void AddCourse();
	void SetNumofAllCourses(int _num);
	void AddStudent();
	void SetNumOfallStudents(int _num);
	//
	void Run();
	void AddStudentToCourse();
	void Add_Grade_toStudentinCourse();

	//get
	Course* GetCourseByindex(int _idx) const;
	int GetNumOfAllCourses() const;
	Student* GetStudentByindex(int _idx) const;
	int GetNumOfAllStudents() const;

	//print
	void PrintCourse() const;
	void PrintStudent() const;



};

#endif