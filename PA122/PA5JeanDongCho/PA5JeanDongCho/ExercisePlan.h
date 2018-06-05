#pragma once
#include <iostream>
#include <fstream>
#include <string>
using std::cout; // we can now use cout without explicitly writing std::cout
using std::endl;
using std::cin;
using std::string;
using std::ifstream;
using std::ofstream;
using std::ios;


class ExercisePlan
{
public:
	//constructor
	ExercisePlan(int newSteps = 0, string newName = nullptr, string newDate = nullptr);
	//copy constructor
	ExercisePlan(ExercisePlan &copy);
	//destructor
	~ExercisePlan();
	//gether & setter
	int getSteps() const;
	string getName() const;
	string getDate() const;
	ExercisePlan getNextPtr() const;
	void setSteps(int newSteps);
	void setName(string newName);
	void setDate(string newDate);
	void setNextPtr(ExercisePlan *const newNextPtr);
	void editGoal();
	void runApp(void);
private:
	int mSteps;
	string mName;
	string mDate;
	ExercisePlan *mpNext;//make it to linked list node
};

std::ifstream & operator >> (std::ifstream &lhs, ExercisePlan &rhs);
std::ifstream & operator << (ExercisePlan &lhs, std::ifstream &rhs);