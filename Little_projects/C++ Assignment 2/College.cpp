#include "College.h"
#include <cstring> // string.h


void College::addDepartment()
{
	cout << "Enter department's name:" << endl;
	string name;
	cin >> name;
	cout << "Enter department's code:" << endl;
	int code;
	cin >> code;

	if (findDepartment(code) != -1) {
		cout << "A department with this code already exists." << endl;
		return;
	}
	Department* newDepartment = new Department(name, code);
	if (numOfDepartments > 0) {
		Department** temp = new Department * [++numOfDepartments];
		for (int i = 0; i < numOfDepartments - 1; i++) {
			temp[i] = departments[i];
		}
		delete[] departments;
		departments = temp;
	}
	else {                                                                                                  
		departments = new Department * [++numOfDepartments];
	}
	departments[numOfDepartments - 1] = newDepartment;
}


void College::addStudentToCollege(Student& newStud) {
	if (numOfStudents > 0) {
		for (int i = 0; i < numOfStudents; i++) {
			if (newStud == *students[i]) {
				cout << "This student is already signed to this college." << endl;
				return;
			}
		}
		Student** temp = new Student * [++numOfStudents];
		for (int i = 0; i < numOfStudents - 1; i++) {
			temp[i] = students[i];
		}
		delete[] students;
		students = temp;
	}
	else {
		students = new Student * [++numOfStudents];
	}
	students[numOfStudents - 1] = new Student(newStud);
}

void College::menu()
{
	while (1)
	{
		fflush(stdin);
		cout << "*************************************************************************" << endl;
		cout << "*************************************************************************" << endl;
		cout << "*************************************************************************" << endl;
		cout << "Welcome to sce. What would you like to do?" << endl;
		cout << "*************************************************************************" << endl;
		cout << "[1] - Add a department to the college." << endl;
		cout << "[2] - Add a course to a department." << endl;
		cout << "[3] - Add a student to a department." << endl;
		cout << "[4] - Register a student to a course." << endl;
		cout << "[5] - Grade a course." << endl;
		cout << "[6] - Print a course's information." << endl;
		cout << "[7] - Print a student's information." << endl;
		cout << "[8] - Print a department's information." << endl; 
		cout << "[9] - Calculate the students with bad academic status." << endl;
		cout << "[10]- Remove a student from a course." << endl;
		cout << "[11]- Exit." << endl;
		cout << "*************************************************************************" << endl;

		int choice;

		switch (choice)
		{
		case 1:
			addDepartment();
			break;
		case 2:
			addCourseToDepartment();
			break;
		case 3:
			addStudentToDepartment();
			break;
		case 4:
			registerStudentToCourse();
			break;
		case 5:
			gradingStudentsInCourse();
			break;
		case 6:
			printCourseInfo();
			break;
		case 7:
			printStudentInfo();
			break;
		case 8:
			printDepartmentInfo();
			break;
		case 9:
			findStudentsWithBadAcademicStat();
			break;
		case 10:
			removeStudentFromCourse();
			break;
		case 11:
			cout << "Thank you, goodbye." << endl;
			return;
			break;
		default:
			cout << "No such option , sorry. Choose again please." << endl;
		}
	}
}