#include "node.h"

node::node(int newRnum, int newIDnum, string newName , string newMail , int newUnits, string newProgram, string newLevel, int newDsize)
{
	mRnum = newRnum;
	mIDnum = newIDnum;
	mName = newName;
	mMail = newMail;
	mUnits = newUnits;
	mProgram = newProgram;
	mLevel = newLevel;
	mDsize = newDsize;
	mMaxSize = 365;
	mDates = new string[365];
}

int node::getRnum() const
{
	return mRnum;
}
int node::getIDnum()const
{
	return mIDnum;
}
string node::getName()const
{
	return mName;
}
string node::getMail()const
{
	return mMail;
}
int node::getUnit()const
{
	return mUnits;
}
string node::getProgram()const
{
	return mProgram;
}
string node::getLevel()const
{
	return mLevel;
}
void node::setRnum(int newRnum)
{
	mRnum = newRnum;
}
void node::setIDnum(int newIDnum)
{
	mIDnum = newIDnum;
}
void node::setUnits(int newUnits)
{
	mUnits = newUnits;
}
void node::setProgram(string newProgram)
{
	mProgram = newProgram;
}
void node::setLevel(string newLevel)
{
	mLevel = newLevel;
}
void node::setDsize(int size)
{
	mDsize = size;
}
void node::setName(string newName)
{
	mName = newName;
}
void node::setMail(string newMail)
{
	mMail = newMail;
}
string node::getAbsence()
{
	string abs = "";
	if (mDsize != 0)
	{
		//cout << mName << ": " << endl;
		for (int i = 1; i < mDsize + 1; i++)
		{
			//cout << "Absence - " << mDates[mDsize - i] << endl;
			abs += mDates[mDsize - i];
			abs += " , ";
		}
	}
	return abs;
}
int node::getAbsencenum()
{
	return mDsize;
}
void node::setAbsence(string newDate)
{
	if (mDsize > 1)
	{

		if (mDates[mDsize - 1] != newDate)
		{
			mDates[mDsize] = newDate;
			mDsize++;
		}
	}
	else
	{
		mDates[mDsize] = newDate;
		mDsize++;
	}

}
void node::editAbsence(string newDate)
{
	if (mDsize > 1)
	{

		
		mDates[mDsize-1] = newDate;
		
	}
	else
	{
		mDates[mDsize] = newDate;
		mDsize++;
	}
}

void node::markAbsence()
{
	// retrieved from stackoverflow - http://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
	time_t t = time(0);   // get time now
	struct tm * now = localtime(&t);
	string date = "";
	int year = (now->tm_year + 1900);
	int month = (now->tm_mon + 1);
	int day = now->tm_mday;
	date = to_string(year);
	date += "-";
	date += to_string(month);
	date += "-";
	date += to_string(day);
	if (mDsize > 1)
	{
		if (mDates[mDsize - 1] != date)
		{
			mDates[mDsize] = date;
			mDsize++;
		}
	}
	else
	{
		mDates[mDsize] = date;
		mDsize++;
	}
	
	
	
}
string node::peekAbsence()
{
	string abs = "";
	if (mDsize != 0)
	{
		//cout << mName << ": " << endl;
		
			//cout << "Absence - " << mDates[mDsize - i] << endl;
			abs = mDates[mDsize - 1];
			
	
	}
	return abs;
}
