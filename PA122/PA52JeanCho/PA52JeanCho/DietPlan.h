#pragma once
#include <iostream>
#include <fstream>
#include <string>
//#include "list.h"
using std::cout; // we can now use cout without explicitly writing std::cout
using std::endl;
using std::cin;
using std::string;
using std::ifstream;
using std::ofstream;
using std::ios;

// Blueprint for a rational number
class DietPlan
{
public:
	// In here will be our well defined interfaces
	// to the object - member functions

	// constructor with default arguments
	DietPlan(int newGoal = 0, string newName = "", string newDate = "");

	// copy constructor - pass-by-value
	DietPlan(const DietPlan &copy);

	~DietPlan(); // destructor

	//DietPlan & operator= (DietPlan &rhs);

	

	// getters/accessors
	int getGoal() const;//constant function, cannot change data members of object(private value)
	string getName() const;
	string getDate() const;
	
	// setters/mutators
	void setGoal(int newGoal);
	void setName(string newName);
	void setDate(string newDate);
	

	void editGoal();
	//bool insertAtFront(int newGoal, string newName, string newDate);
private:
	// attributes - data members
	// rational numbers may defined as:
	// numerator / denominator
	int mGoal;//2integer = 8 byte
	string  mName;
	string mDate;
	
};

//std::ifstream & operator >> (std::ifstream &lhs, DietPlan &rhs);
ofstream & operator << (ofstream &lhs, DietPlan &rhs); // write plan to file
ifstream& operator >> (ifstream& lhs, DietPlan &rhs);//definiton on fitnessappwrapper.cpp
