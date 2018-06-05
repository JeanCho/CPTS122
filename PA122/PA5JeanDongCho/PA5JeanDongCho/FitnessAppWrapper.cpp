#include "FitnessAppWrapper.h"
FitnessAppWrapper::FitnessAppWrapper()
{
	
	mInputStream.open("DietPlan.txt", ios::in);
	mOutputStream.open("Dietout.txt", ios::out);
}

FitnessAppWrapper::~FitnessAppWrapper()
{
	cout << "InsideFitnessAppWrapper's destructor! Closing open files!" << endl;

	// is_open returns true of file is open! If open () failed during in the construction of the ListApp,
	// then we will not try to close the stream!
	if (mInputStream.is_open())
	{
		mInputStream.close();
	}
	if (mOutputStream.is_open())
	{
		mOutputStream.close();
	}
}

void FitnessAppWrapper::displayDailyPlan(int check)
{
	if (check == 0)//Diet plan
	{
		cout << "Name: " << this->mDplan.getName << endl;
		cout << "Goal: " << this->mDplan.getGoal << endl;
		cout << "Date: " << this->mDplan.getDate << endl;
	}
	else if (check == 1)//Exercise Plan
	{
		cout << "Name: " << this->mEplan.getName << endl;
		cout << "Goal: " << this->mEplan.getSteps << endl;
		cout << "Date: " << this->mEplan.getDate << endl;

	}
}

void FitnessAppWrapper::displayWeeklyPlan(int check)
{
	DietPlan *d = nullptr;
	ExercisePlan *e = nullptr;
	if (check == 0)//Diet plan
	{
		while()
		{
			cout << "Name: " << this->mDplan.getName << endl;
			cout << "Goal: " << this->mDplan.getGoal << endl;
			cout << "Date: " << this->mDplan.getDate << endl;
		}
	}
	else if (check == 1)//Exercise Plan
	{
		while ()
		{
			cout << "Name: " << this->mEplan.getName << endl;
			cout << "Goal: " << this->mEplan.getSteps << endl;
			cout << "Date: " << this->mEplan.getDate << endl;
		}

	}
}
ExercisePlan * makeEplan(int newSteps, string newName, string newDate)   // will only call within insert functions
{
	ExercisePlan *pMem = new ExercisePlan(newSteps, newName, newDate);  // ListNode constructor is invoked!

	return pMem;
}
DietPlan * makeDplan(int newGoal, string newName, string newDate)
{
	DietPlan *pMem = new DietPlan(newGoal, newName, newDate);

	return pMem;
}
void FitnessAppWrapper::loadDailyPlan(fstream &fileStream,int check) 
{
	DietPlan * d = nullptr;
	string line;
	if (!fileStream.eof())
	{
		d = makeDplan(0, nullptr, nullptr);
		fileStream >> *d;

		//todo: add 'd' to this->list
		this->mlist.insertAtFront(d->getGoal, d->getName, d->getDate, check);//0 : add it in to diet plan, 1 :exercise plan
		free(d);
	}

	
}
void FitnessAppWrapper::loadWeeklyPlan(fstream &fileStream)
{
	if (fileStream)
	{
		fileStream >> *this;
	}
	
}


void FitnessAppWrapper::displayMenu()
{
	cout << "1.Load weekly diet plan from file." << endl;
	cout << "2.Load weekly exercise plan from file." << endl;
	cout << "3.Store weekly diet plan to file." << endl;
	cout << "4.Store weekly exercise plan to file." << endl;
	cout << "5.Display weekly diet plan to screen." << endl;
	cout << "6.Display weekly exercise plan to screen." << endl;
	cout << "7.Edit daily diet plan." << endl;
	cout << "8.Edit daily exercise plan." << endl;
	cout << "9.Exit." << endl;
}

void FitnessAppWrapper::runApp(void)
{
	int choice = 0;
	do {
		this->displayMenu();
		scanf("%d", &choice);
		getchar();
		switch (choice)
		{
		case 1:
			this->loadWeeklyPlan(&(* mInputStream));
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;

	
		}

	} while (choice != 9);
	
}





fstream& operator >> (fstream &fileStream, FitnessAppWrapper &rhs) {
	DietPlan * d = nullptr;
	string line;
	while (!fileStream.eof())
	{
		d = makeDplan(0, nullptr, nullptr);
		fileStream >> *d;
		
		//todo: add 'd' to this->list
		rhs.addDetail(d->getGoal,d->getName,d->getDate,0);//add it in to diet plan
		free(d);
	}

	return fileStream;
}

bool FitnessAppWrapper::addDetail(int newData, string newName, string newDate, int check)
{
	mlist.insertAtFront(newData, newName, newDate, check);
}

std::istream& operator>> (std::istream& lhs, DietPlan &rhs) {
	std::string input;
	stringstream ss;
	int goal = 0;
	lhs >> input;
	rhs.setName(input);
	lhs >> input;
	ss << input;
	ss >> goal;
	rhs.setGoal(goal);
	lhs >> input;
	rhs.setDate(input);
	return lhs;
}