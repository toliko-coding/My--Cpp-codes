#include "Menu.h"
#include <string.h>

using namespace std;


//ctr 
Menu::Menu():AllCourses(nullptr) , NumofAllCourses(0) , AllStudents(nullptr) , NumOfallStudents(0)
{
	cout << "Defualt MENU ctr" << endl;
}

Menu::Menu(Course** _allcourses, int _numofallcourses, Student** _allstudents, int _numofallstudents):
	AllCourses(_allcourses) , NumofAllCourses(_numofallcourses) , AllStudents (_allstudents) , NumOfallStudents (_numofallstudents)
{
	cout << "Non Defualt MENU CTR" << endl;
}

Menu::~Menu()
{
	if (AllCourses)
	{
		for (int i = 0; i < NumofAllCourses; i++)
		{
			delete AllCourses[i];
		}
		delete[] AllCourses;
		cout << "~MENU::AllCourses" << endl;


	}
	if (AllStudents)
	{
		for (int i = 0; i < NumOfallStudents; i++)
		{
			delete AllStudents[i];
		}
		delete[] AllStudents;
		cout << "~MENU:: AllStudents" << endl;

	}
	cout << "Object MENU have been DELETED ! " << endl;

}

//set
void Menu::AddCourse()
{
	if(AllCourses == nullptr)
	{ 
		AllCourses = new Course*;
		Course* temp = new Course;
		cin >> *temp;

		AllCourses[0] = temp;
		NumofAllCourses++;
	}

	else
	{
		NumofAllCourses++;
		Course* tempC = new Course;
		cin >> *tempC;
		Course** templist = new Course* [NumofAllCourses];
		int i = 0;
		for (i; i < NumofAllCourses - 1; i++)
		{
			templist[i] = AllCourses[i];
		}
		templist[i] = tempC;
		delete AllCourses;
		AllCourses = templist;
	}
	cout << "Course Added to the list!" << endl;
}

void Menu::SetNumofAllCourses(int _num)
{
	NumofAllCourses = _num;
}

void Menu::AddStudent()
{
	if (AllStudents == nullptr)
	{
		AllStudents = new Student*;
		Student* tempS = new Student;
		cin >> *tempS;

		AllStudents[0] = tempS;
		NumOfallStudents++;
	}

	else
	{
		Student* s1 = new Student;
		cin >> *s1;
		NumOfallStudents++;

		Student** templist = new Student* [NumOfallStudents];
		int i = 0;
		for (i; i < NumOfallStudents - 1; i++)
		{
			templist[i] = AllStudents[i];
		}
		templist[i] = s1;

		delete AllStudents;
		AllStudents = templist;

		
	}
	cout << "Student have been added !" << endl;
}

void Menu::SetNumOfallStudents(int _num)
{
	NumOfallStudents = _num;
}

//others
void Menu::Run()
{
	cout << "Hi and Welcome to the Menu , Please Choose what you want to do : " << endl; 

	bool flag = true;

	while (flag)
	{
		cout << endl << "*******M**E**N**U***********" << endl;
		cout << "1.Add New Course to the list" << endl;
		cout << "2.Add New Student to the list " << endl;
		cout << "3.Add Student by ID to Course by Number Of the Course" << endl;
		cout << "4.Add Grade to Student By ID to Course by Course Numer" << endl;
		cout << "5.Print Course by Course Num (it will print also all the Students + Grades)" << endl;
		cout << "6.Print Student by ID (it will also print all his courses)" << endl;
		cout << "7. EXIT" << endl;

		int choose;
		cin >> choose;
		cout << endl;

		if (choose == 1)
		{
			AddCourse();
		}
		else if (choose == 2)
		{
			AddStudent();
		}
		else if (choose == 3)
		{
			AddStudentToCourse();
		}
		else if (choose == 4)
		{
			Add_Grade_toStudentinCourse();
		}
		else if (choose == 5)
		{
			PrintCourse();
		}
		else if (choose == 6)
		{
			PrintStudent();
		}
		else if (choose == 7)
		{
			flag = false;
		}

		else
		{
			cout << "incorect selection ! , please choose again " << endl;
		}


	}
}

void Menu::AddStudentToCourse()
{
	cout << "Please Enter the Student ID :" << endl;
	string id;
	cin >> id;

	cout << endl << "Please Enter Course Num :" << endl;
	int cNum;
	cin >> cNum;

	int idxS = -1; // index of the serch
	int idxC = -1;

	int i = 0;
	int j = 0;

	if (NumOfallStudents == 0)
	{
		cout << "There Are no Students that exict to add to Course" << endl;
	}
	else if (NumofAllCourses == 0)
	{
		cout << "You need to create Course before adding students" << endl;
	}
	else
	{
		//Student Search
		for (i; i < NumOfallStudents; i++)
		{
			if (AllStudents[i]->GetID() == id)
			{
				idxS = i;
				cout << "Student Founded" << endl;
			}
		}

		if (idxS == -1)
		{
			cout << "Student NOT founded !" << endl;
			
		}


		//Course Serch
		for (j; j < NumofAllCourses; j++)
		{
			if (AllCourses[j]->getCourseNum() == cNum)
			{
				idxC = j;
				cout << "Course Have been found" << endl;
			}
		}

		if (idxC == -1)
		{
			cout << "Course Have NOT found !" << endl;
		}

		if (idxC != -1 && idxS != -1)
		{
			*AllCourses[idxC] += *AllStudents[idxS];
			cout << "Student " << id << " Added to Course num " << cNum << endl;

		}
	}

	

}

void Menu::Add_Grade_toStudentinCourse()
{
	cout << "Enter Course ID :" << endl;
	int cNum;
	cin >> cNum;

	cout << "Enter Student ID :" << endl;
	string sID;
	cin >> sID;

	cout << "Enter The Grade for this Student:" << endl;
	int grade;
	cin >> grade;

	int cidx = -1;
	int sidx = -1;


	int i = 0;
	for (i; i < NumofAllCourses; i++)
	{
		if (AllCourses[i]->getCourseNum() == cNum)
		{
			cidx = i;
			cout << "Course found" << endl;
		}
	}
	if (cidx == -1)
	{
		cout << "Course Not FOund" << endl;
	}

	i = 0;

	for (i; i < NumOfallStudents; i++)
	{
		if (AllStudents[i]->GetID() == sID)
		{
			sidx = i;
			cout << "Student Found !" << endl;
		}
	}

	if (sidx == -1)
	{
		cout << "Student not Found !" << endl;
	}

	if (sidx != -1 && cidx != -1)
	{
		AllCourses[cidx]->SetGradetoIdx(sidx, grade);
		cout << "Grade have been Added to the Student" << endl;
	}
}


//get
Course* Menu::GetCourseByindex(int _idx) const
{
	return AllCourses[_idx];
}

int Menu::GetNumOfAllCourses() const
{
	return NumofAllCourses;
}

Student* Menu::GetStudentByindex(int _idx) const
{
	return AllStudents[_idx];
}

int Menu::GetNumOfAllStudents() const
{
	return NumOfallStudents;
}

//print

void Menu::PrintCourse() const
{

	cout << "Please Enter Course ID :" << endl;
	int id;
	cin >> id;
	int i = 0;

	bool flag = false;
	for (i; i < NumofAllCourses; i++)
	{
		if (AllCourses[i]->getCourseNum() == id)
		{
			cout << *AllCourses[i] << endl;;
			flag = true;
		}
	}
	
	if (flag == false)
	{
		cout << "Course not found !" << endl;
	}

	
}

void Menu::PrintStudent() const
{
	cout << "Please Enter Student ID :" << endl;
	string tempid;
	cin >> tempid;

	int i = 0;
	bool flag = false;

	for (i; i < NumOfallStudents; i++)
	{
		if (AllStudents[i]->GetID() == tempid)
		{
			cout << *AllStudents[i];
			flag = true;
		}
	}

	if (flag == false)
	{
		cout << "Student with ID : " << tempid << " is Not found " << endl;
	}

	
	
}


