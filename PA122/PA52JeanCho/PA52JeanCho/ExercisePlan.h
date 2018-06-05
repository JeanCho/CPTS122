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
	//ExercisePlan() {};
	ExercisePlan(int newSteps =0, string newName = "", string newDate = "");
	//copy constructor
	ExercisePlan(ExercisePlan &copy);
	//destructor
	~ExercisePlan();
	//gether & setter
	int getSteps() const;
	string getName() const;
	string getDate() const;
	
	void setSteps(int newSteps);
	void setName(string newName);
	void setDate(string newDate);
	
	void editGoal();
	
private:
	int mSteps;
	string mName;
	string mDate;
	
};

ifstream & operator >> ( ifstream &rhs, ExercisePlan &lhs);
ofstream & operator << ( ofstream &rhs, ExercisePlan &lhs);
