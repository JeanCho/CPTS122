#include "ExercisePlan.h"
//constructor
ExercisePlan::ExercisePlan(int newSteps , string newName , string newDate )
{
	mSteps = newSteps;
	mName = newName;
	mDate = newDate;
}
//copy constructor
ExercisePlan::ExercisePlan(ExercisePlan &copy)
{
	mSteps = copy.getSteps();
	mName = copy.getName();
	mDate = copy.getSteps();
}
//destructor
ExercisePlan::~ExercisePlan()
{
	cout << "Inside ExercisePlan's destructor" << endl;
}
//gether & setter
int  ExercisePlan::getSteps() const
{
	return mSteps;
}
string  ExercisePlan::getName() const
{
	return mName;
}
string  ExercisePlan::getDate() const
{
	return mDate;
}
void  ExercisePlan::setSteps(int newSteps)
{
	mSteps = newSteps;
}
void  ExercisePlan::setName(string newName)
{
	mName = newName;
}
void  ExercisePlan::setDate(string newDate)
{
	mDate = newDate;
}
void ExercisePlan::editGoal()
{
	int newgoal = 0;
	cout << "Please type new goal" << endl;
	cin >> newgoal;
	mSteps = newgoal;
}