#include <iostream>
using namespace std;
// multiple  and virtual inheritance
#include <iostream>
#include <string>
using namespace std;

class Person {
  protected:
    long m_id;
	string m_name;
	string m_address;
	static int m_count;
  public:
	  Person(char* ="UNKNOWN",char* ="UNKNOWN");
	  static int GetCount() {return m_count;}
	  void SetName(char* name){m_name=name;}
	  void SetAddress(char* address){m_address=address;}
	  string GetName()const{return m_name;}
	  string GetAddress()const{return m_address;}
	  void Print()const;
	  ~Person(){cout<<"I am Person dtor"<<endl;}
};
Person::Person(char *name,char *address):m_name(name),m_address(address)
{	cout<<"I am Person ctor"<<endl; m_count++;    m_id=1000 + m_count;   }
void Person::Print()const
{
	cout<<endl<<"Data for Person - id :"<<m_id<<" Name : "<<m_name
		<<" Address : "<<m_address<<endl;
}
//-----------------------------------------------------------------------
class Student: virtual public Person{
	unsigned m_courses;
public:
	Student(unsigned =1,char* ="UNKNOWN",char* ="UNKNOWN");
	void SetCourses(unsigned cours){m_courses=cours;}
	unsigned GetCourses ()const{return m_courses;}
	void Print()const;
	~Student(){cout<<"I am Student dtor"<<endl;}
};
Student::Student(unsigned  number,char * name,char* address):Person(name,address),m_courses(number)
{cout<<"I am Student ctor"<<endl;}
void Student::Print()const
{
	Person::Print();
	cout<<" Number of courses for student = "<<m_courses<<endl;
}
//-----------------------------------------------------------------------
class Employee: virtual public Person{ 
	unsigned m_salary;
public:
	Employee(unsigned =1000,char* ="UNKNOWN",char* ="UNKNOWN");
	void SetSalary(unsigned salary){m_salary=salary;}
	unsigned GetSalary ()const{return m_salary;}
	void Print()const;
	~Employee(){cout<<"I am Employee dtor"<<endl;}
};
Employee::Employee(unsigned  salary,char * name,char* address):Person(name,address),m_salary(salary)
{cout<<"I am Employee ctor"<<endl;}
void Employee::Print()const
{
	Person::Print();
	cout<<" Salary for employee = "<<m_salary<<endl;
}
//-----------------------------------------------------------------------
class Assistant:public Student,public Employee{
public:
 
	Assistant(char* ="UNKNOWN",char* ="UNKNOWN",unsigned =1,unsigned=1000);
	void Print()const;
	~Assistant(){cout<<"I am Assistant dtor"<<endl;}
};
Assistant::Assistant(char* name,char* address,unsigned courses,unsigned salary)
:Student(courses),Employee(salary),Person(name,address)
{cout<<"I am Assistant ctor"<<endl;}
void Assistant::Print() const
{	
	cout<<endl<<"Printing Assistant data :";
	Student::Print();
	Employee::Print();
}
//-----------------------------------------------------------------------
int Person::m_count=0;
int main () 
{
  Assistant make("Make Joe","123 Str, NY",5,8000);
  make.Print();
  cout<<endl <<"============= Student ======================"<<endl<<endl;
  Student yan(3,"Yan Kohen","245 Str, NY");
  yan.Print();
  cout<<" ===================  end of program   ================="<<endl;
  return 0;
}

