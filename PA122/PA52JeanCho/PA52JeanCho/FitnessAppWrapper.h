#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "DietPlan.h"
#include "ExercisePlan.h"
#include <sstream>
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::fstream;
using std::ofstream;
using std::ios;
using std::getline;
using std::stringstream;
using std::string;

class FitnessAppWrapper
{
public:

	FitnessAppWrapper();// default constructor - open files
	~FitnessAppWrapper(); // destructor
	
	void runApp(void);//run whole app
	//load files to plan, 2 in 1 function! diecide by check;
	void loadDailyPlan(ifstream &fileStream, int check);
	void loadWeeklyPlan(ifstream &fileStream, int check);
	//display plan(array)
	void displayDailyPlan(int check);
	void displayWeeklyPlan(int check);
	//sotre plan
	void storeDailyPlan(ofstream &fileStream, int check);
	void storeWeeklyPlan(ofstream &fileStream, int check);
	//display menu with 9 options
	void displayMenu();
	//edit plan(plan's goal)
	void EditDailyPlan(int check);
	bool addDetail(int newData, string newName, string newDate, int check);
private:
	ifstream mDietInput;
	ifstream mExInput;
	ofstream mDietOutput;
	ofstream mExOutput;
	ExercisePlan mEplan[7];
	DietPlan mDplan[7];
	//List mlist;



};
//ExercisePlan * makeEplan(int newSteps, string newName, string newDate);    // will only call within insert functions
//DietPlan * makeDplan(int newGoal, string newName, string newDate);

