#include "Student.h"

Student::Student(const std::string &newName , int newAge, int newGender, int newHeight, int newNumCourses, int newTotalCredits) : Person(newName, newAge, newGender, newHeight)
{
	numCourses = newNumCourses;
	totalCredit = newTotalCredits;
	//vector<Course> vCourses;
	
}
Student::Student(Student &copy)	:Person(copy)
{
	numCourses = copy.numCourses;
	totalCredit = copy.totalCredit;
}

Student::~Student()
{
	cout << "Inside Destructor of Student" << endl;
}
void Student::setCourseList(Course C)
{
	coursesTaken.push_back(C);
}
int Student::totalCredits()
{
	int total = 0;
	for (int i = 0; i <coursesTaken.size(); i++)
	{
		total += coursesTaken[i].credits;

	}
	return total;
}
double Student::GPA()
{
	double gpa = 0.0;
	if (coursesTaken.size() != 0)
	{
		for (int i = 0; i < coursesTaken.size(); i++)
		{
			if (coursesTaken[i].curGrad == 'A')
			{
				gpa += 4.0;
			}
			if (coursesTaken[i].curGrad == 'B')
			{
				gpa += 3.0;
			}
			if (coursesTaken[i].curGrad == 'C')
			{
				gpa += 2.0;
			}
			if (coursesTaken[i].curGrad == 'D')
			{
				gpa += 1.0;
			}
		}
		gpa = gpa / coursesTaken.size();
		return gpa;
	}
	else
	{
		cout << "0 Courses taken!!" << endl;
		return 0;
	}
}