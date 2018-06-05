#include "FitnessAppWrapper.h"
FitnessAppWrapper::FitnessAppWrapper()
{

	this->mDietInput.open("dietplan7.txt", ios::in);
	this->mExInput.open("exerciseplan7.txt", ios::in);
	this->mDietOutput.open("dietout.txt", ios::out);
	this->mExOutput.open("exout.txt", ios::out);
}

FitnessAppWrapper::~FitnessAppWrapper()
{
	cout << "InsideFitnessAppWrapper's destructor! Closing open files!" << endl;

	// is_open returns true of file is open! If open () failed during in the construction of the ListApp,
	// then we will not try to close the stream!
	if (mDietInput.is_open())
	{
		mDietInput.close();
	}
	if (mDietOutput.is_open())
	{
		mDietOutput.close();
	}
	if (mExInput.is_open())
	{
		mExInput.close();
	}
	if (mExOutput.is_open())
	{
		mExOutput.close();
	}


}

void FitnessAppWrapper::displayDailyPlan(int check)
{
	int choice = 0;
	cout << "Please type the day you want to display:[1-7]" << endl;
	cin >> choice;
	if (check == 0)//Diet plan
	{
		cout << "Name: " << this->mDplan[choice-1].getName() << endl;
		cout << "Goal: " << this->mDplan[choice-1].getGoal() << endl;
		cout << "Date: " << this->mDplan[choice-1].getDate() << endl;
	}
	else if (check == 1)//Exercise Plan
	{
		cout << "Name: " << this->mEplan[choice-1].getName() << endl;
		cout << "Goal: " << this->mEplan[choice-1].getSteps() << endl;
		cout << "Date: " << this->mEplan[choice-1].getDate() << endl;

	}
	cout << "All File closed" << endl;
}

void FitnessAppWrapper::displayWeeklyPlan(int check)
{
	DietPlan *d = nullptr;
	ExercisePlan *e = nullptr;
	if (check == 0)//Diet plan
	{
		for (int i =0; i<7;i++ )
		{
			cout <<i+1<< ".Name: " << this->mDplan[i].getName()<< endl;
			cout << "Goal: " << this->mDplan[i].getGoal()<< endl;
			cout << "Date: " << this->mDplan[i].getDate()<< endl;
		}
	}
	else if (check == 1)//Exercise Plan
	{
		for (int i = 0; i<7; i++)
		{
			cout << i+1<<".Name: " << this->mEplan[i].getName()<< endl;
			cout << "Goal: " << this->mEplan[i].getSteps()<< endl;
			cout << "Date: " << this->mEplan[i].getDate()<< endl;
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
void FitnessAppWrapper::loadDailyPlan(ifstream &fileStream, int check)
{
	//DietPlan * d = nullptr;
	//ExercisePlan * e = nullptr;
	string line;
	if (!fileStream.eof())
	{
		if (check == 0)
		{
			//d = makeDplan(0, nullptr, nullptr);
			//fileStream >> *d;
			//this->addDetail(d->getGoal(), d->getName(), d->getDate(), check); 
			//	//todo: add 'd' to this->list
			//free(d);
			
			fileStream >> this->mDplan[0];

		}
		else if (check == 1)
		{
			/*e = makeEplan(0, nullptr, nullptr);
			fileStream >> *e;
			this->addDetail(e->getSteps(), e->getName(), e->getDate(), check);
			free(e);*/
			fileStream >> this->mEplan[0];
		}
		
		cout << "Load Complete" << endl << endl;
	}


}
void FitnessAppWrapper::loadWeeklyPlan(ifstream &fileStream,int check)
{
	//DietPlan * d = nullptr;
	//ExercisePlan * e = nullptr;
	string line;
	if (!fileStream.eof())
	{
		if (check == 0)
		{
			for (int i = 0; i < 7; i++)
			{
				//d = makeDplan(0, "", "");
				//fileStream >> *d;
				//this->addDetail(d->getGoal(), d->getName(), d->getDate(), check);
				////todo: add 'd' to this->list
				//free(d);
				fileStream >> this->mDplan[i];
			}
		}
		else if (check == 1)
		{
			for (int i = 0; i < 7; i++)
			{
				//d = makeDplan(0, "", "");
				//fileStream >> *d;
				//this->addDetail(d->getGoal(), d->getName(), d->getDate(), check);
				////todo: add 'd' to this->list
				//free(d);
				fileStream >> this->mEplan[i];
			}
		}
		cout << "Load Complete" << endl << endl;

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

void FitnessAppWrapper::EditDailyPlan(int check)
{
	int choice = 0;
	cout << "Please type the day you want to edit the goal:[1-7]" << endl;
	cin >> choice;
	if (check == 0)//Diet plan
	{
		cout << "Changing:" << endl;

		cout << this->mDplan[choice - 1].getName() << endl;
		cout << this->mDplan[choice - 1].getGoal() << endl;
		this->mDplan[choice - 1].editGoal();
		cout << this->mDplan[choice - 1].getName() << endl;
		cout << this->mDplan[choice - 1].getGoal() << endl;
		cout << "Edit Complete" << endl;
	}
	else if (check == 1)//Exercise Plan
	{
		
			cout << "Changing:" << endl;
			cout << this->mEplan[choice - 1].getName() << endl;
			cout << this->mEplan[choice - 1].getSteps() << endl;
			this->mEplan[choice - 1].editGoal();
			cout << this->mEplan[choice - 1].getName() << endl;
			cout << this->mEplan[choice - 1].getSteps() << endl;
			cout << "Edit Complete" << endl;

	}
}
void FitnessAppWrapper::runApp(void)
{
	int choice = 0;
	do {
		this->displayMenu();
		/*scanf("%d", &choice);
		getchar();*/
		std::cin >> choice;
		switch (choice)
		{
		case 1://load weekly diet plan
			loadWeeklyPlan(mDietInput, 0);
			break;
		case 2://load weekly exercise plan
			loadWeeklyPlan(mExInput, 1);
			break;
		case 3://store weekly diet plan
			storeWeeklyPlan(mDietOutput, 0);
			break;
		case 4://store weekly exercise plan
			storeWeeklyPlan(mExOutput, 1);
			break;
		case 5://display weekly diet plan
			displayWeeklyPlan(0);
			break;
		case 6://display weekly exercise plan
			displayWeeklyPlan(1);
			break;
		case 7://edit daily diet plan
			EditDailyPlan(0);
			break;
		case 8://edit daily exercise plan
			EditDailyPlan(1);
			break;


		}

	} while (choice != 9);
	mDietInput.close();
	mExInput.close();
	mDietOutput.close();
	mExOutput.close();

}


bool FitnessAppWrapper::addDetail(int newData, string newName, string newDate, int check)
{
	int i = 0;
	bool success = false;
	if (check == 0)//if its dietplan
	{
		while (mDplan[i].getGoal() != 0)
		{
			i++;
		}
		mDplan[i].setDate(newDate);
		mDplan[i].setGoal(newData);
		mDplan[i].setName(newName);
		success = true;
	}
	else if (check == 1)
	{
		while (mEplan[i].getSteps() != 0)
		{
			i++;
		}
		mEplan[i].setDate(newDate);
		mEplan[i].setName(newName);
		mEplan[i].setSteps(newData);
		success = true;
	}
	return success;
}
// >>operators for Diet and Exercise Plans
ifstream& operator >> (ifstream& lhs, DietPlan &rhs) 
{
	string input;
	int goal = 0;
	lhs >> input;
	rhs.setName(input);
	lhs >> goal;
	/*stringstream ss(input);
	ss >> goal;*/
	rhs.setGoal(goal);
	lhs >> input;
	rhs.setDate(input);
	//lhs >> input;//flush the empty line
	return lhs;
}
ifstream& operator >> (ifstream &lhs, ExercisePlan &rhs) {
	string input;
	int goal = 0;
	lhs >> input;
	rhs.setName(input);
	lhs >> goal;
	/*stringstream ss(input);
	ss >> goal;*/
	rhs.setSteps(goal);
	lhs >> input;
	rhs.setDate(input);
	//lhs >> input;//flush the empty line
	return lhs;
}
ofstream & operator << ( ofstream &lhs,DietPlan &rhs ) // write plan to file
{
	string input;
	string a;
	int goal = 0;
	lhs << rhs.getName() << endl;
	lhs << rhs.getGoal() << endl;
	lhs << rhs.getDate() << endl;
	//a = rhs.getName(); //>> input;
	//input += a;
	//input += "\n";
	//input += rhs.getGoal();
	//input += "\n";
	//input += rhs.getDate();
	//input += "\n";
	//lhs << input;
	//rhs.write(input);


	return lhs;
}

ofstream & operator << (ofstream &lhs, ExercisePlan &rhs) // write plan to file
{
	string input;
	string a;
	int goal = 0;
	lhs << rhs.getName() << endl;
	lhs << rhs.getSteps() << endl;
	lhs << rhs.getDate() << endl;
	//a = rhs.getName(); //>> input;
	//input += a;
	//input += "\n";
	//input += rhs.getSteps();
	//input += "\n";
	//input += rhs.getDate();
	//input += "\n";
	//rhs.write(input);

	lhs << input;
	return lhs;
}


void FitnessAppWrapper::storeDailyPlan(ofstream &fileStream, int check)
{
	int choice = 0;
	cout << "Please type the day you want to store:[1-7]" << endl;
	cin >> choice;
	if (fileStream.is_open())
	{
		if (check == 0)
		{
			//d = makeDplan(0, "", "");
				//fileStream >> *d;
				//this->addDetail(d->getGoal(), d->getName(), d->getDate(), check);
				////todo: add 'd' to this->list
				//free(d);
				fileStream << this->mDplan[choice];
			
		}
		else if (check == 1)
		{
			

				fileStream << this->mEplan[choice];
			
		}

		cout << "Storing Complete" << endl << endl;
	}
}
void FitnessAppWrapper::storeWeeklyPlan(ofstream &fileStream, int check)
{
	string line;
	if (fileStream.is_open())
	{
		if (check == 0)
		{
			for (int i = 0; i < 7; i++)
			{
				//d = makeDplan(0, "", "");
				//fileStream >> *d;
				//this->addDetail(d->getGoal(), d->getName(), d->getDate(), check);
				////todo: add 'd' to this->list
				//free(d);
				fileStream << this->mDplan[i] ;
			}
		}
		else if (check == 1)
		{
			for (int i = 0; i < 7; i++)
			{
				
				fileStream << this->mEplan[i]  ;
			}
		}

		cout << "Storing Complete" << endl << endl;
	}

}

//fstream& operator >> (fstream &fileStream, FitnessAppWrapper &rhs) {
//	DietPlan * d = nullptr;
//	string line;
//	while (!fileStream.eof())
//	{
//		//d = makeDplan(0, nullptr, nullptr);
//		fileStream >> *d;
//
//		//todo: add 'd' to this->list
//		rhs.addDetail(d->getGoal, d->getName, d->getDate, 0);//add it in to diet plan
//		free(d);
//	}
//
//	return fileStream;
//}