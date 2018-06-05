#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Person.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;
using std::istream;
using std::vector;
#include "Person.h"
class Student : public Person
{
public:
	Student(const std::string &newName , int newAge , int newGender, int newHeight,int newNumCourses,int newTotalCredits);
	Student(Student &copy);
	~Student();
	int getNumCourses() const;
	int totalCredits();
	double GPA();
	struct Course {
		string courseName;
		int credits;
		char curGrad;
		Course() :courseName(""), credits(0), curGrad('N') {
		}
	};
	void setCourseList(Course C);

private:
	
	vector<Course> coursesTaken;
	int numCourses;
	int totalCredit;
		
};
