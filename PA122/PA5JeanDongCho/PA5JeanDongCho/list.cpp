#include "list.h"

List::List()
{
	mEhead = nullptr;
	mDhead = nullptr;
}

List::List(const List &copyList)
{
	ExercisePlan *pEtemp = copyList.getExerciseHead;
	ExercisePlan *pEcur;
	DietPlan *pDtemp = copyList.getDietHead;
	ExercisePlan *pDcur;

}
bool List::insertAtFront(int newData, string newName, string newDate, int check)
{
	
	if (check == 0)//if it is a diet plan
	{
		DietPlan *pMem = makeDplan(newData,newName,newDate);
		bool success = false;                   // C++ has built in bool types - false, true

		if (pMem != nullptr)
		{
			success = true; // allocated memory successfully
							// pMem is pointing to a ListNode object, but a List object does not have direct access to it; must use a setter!
			pMem->setNextPtr(mDhead);
			mDhead = pMem;
			success = true;
		}

		return success;
	}
	else if (check == 1)
	{
		ExercisePlan *pMem = makeEplan(newData, newName, newDate);
		bool success = false;
		if (pMem != nullptr)
		{
			success = true; // allocated memory successfully
							// pMem is pointing to a ListNode object, but a List object does not have direct access to it; must use a setter!
			pMem->setNextPtr(mEhead);
			mEhead = pMem;
			success = true;
		}

		return success;
	}
	
	
}
ExercisePlan *List:: makeEplan(int newSteps, string newName, string newDate)    // will only call within insert functions
{
	ExercisePlan *pMem = new ExercisePlan(newSteps,newName,newDate);  // ListNode constructor is invoked!

	return pMem;
}

DietPlan* List::makeDplan(int newGoal, string newName, string newDate)
{
	DietPlan *pMem = new DietPlan(newGoal, newName, newDate);

	return pMem;
}