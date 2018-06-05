#pragma once
#include <iostream>
#include <fstream>
#include "DietPlan.h"
#include "ExercisePlan.h"
#include "list.h"
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::fstream;
using std::ofstream;
using std::ios;
class FitnessAppWrapper
{
public:

	FitnessAppWrapper();// default constructor - open files
	~FitnessAppWrapper(); // destructor
	
	void runApp(void);  
	void loadDailyPlan(fstream &fileStream, int check);
	void loadWeeklyPlan(fstream &fileStream);
	void displayDailyPlan(int check);
	void displayWeeklyPlan(int check);
	void storeDailyPlan();
	void storeWeeklyPlan();
	void displayMenu();
	bool addDetail(int newData, string newName, string newDate, int check);
	void displayMenu();
private:
	const ifstream mInputStream; 
	ofstream mOutputStream; 
	ExercisePlan mEplan;
	DietPlan mDplan;
	List mlist;



};
ExercisePlan * makeEplan(int newSteps, string newName, string newDate);    // will only call within insert functions
DietPlan * makeDplan(int newGoal, string newName, string newDate);
