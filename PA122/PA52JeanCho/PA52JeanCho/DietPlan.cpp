#include "DietPlan.h"
//#include "list.h"
//default
DietPlan::DietPlan(int newGoal, string newName, string newDate)
{
	mGoal = newGoal;
	mName = newName;
	mDate = newDate;
}

DietPlan::DietPlan(const DietPlan &copy)
{
	mGoal = copy.mGoal;
	mName = copy.mName;
	mDate = copy.mDate;
}

DietPlan::~DietPlan()
{

	cout << "Inside DietPlan's destructor" << endl;
}
//gathers
int DietPlan::getGoal() const
{
	return mGoal;
}

string DietPlan::getName()const
{
	return mName;
}

string DietPlan::getDate()const
{
	return mDate;
}
//setters
void DietPlan::setGoal(int newGoal)
{
	mGoal = newGoal;
}

void DietPlan::setName(string newName)
{
	mName = newName;
}

void DietPlan::setDate(string newDate)
{
	mDate = newDate;
}


void DietPlan::editGoal()
{
	int newgoal = 0;
	cout << "Please type new goal" << endl;
	cin >> newgoal;
	mGoal = newgoal;
}
//bool DietPlan::insertAtFront(int newGoal, string newName, string newDate)
//{
//	DietPlan *pMem = makeDplan(newData, newName, newDate);
//	bool success = false;                   // C++ has built in bool types - false, true
//
//	if (pMem != nullptr)
//	{
//		success = true; // allocated memory successfully
//						// pMem is pointing to a ListNode object, but a List object does not have direct access to it; must use a setter!
//		pMem->setNextPtr(mDhead);
//		mDhead = pMem;
//		success = true;
//	}
//
//	return success;
//}

//ifstream & operator  >> (ifstream &input, DietPlan &rhs)
//{
//	stringstream ss;
//	int check = 0,Goal=0;
//	string Name = "";
//	string Date = "";
//	string line = "";
//	string Data = "";
//	string blank = "";
//	DietPlan pCur = rhs;
//	while (!input.eof())
//	{
//		getline(input, Name);
//		getline(input,Data);
//		getline(input,Date);
//		getline(input,blank );//blank line
//		ss << Data;
//		ss >> Goal;
//		
//		pCur.setGoal(Goal);
//		pCur.setName(Name);
//		pCur.setDate(Date);
//
//		pCur = pCur.getNextPtr;
//		
//		
//		
//	}
//	return input;
//}