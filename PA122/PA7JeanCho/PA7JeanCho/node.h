#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;

using std::string;
using std::to_string;
using std::ios;

class node
{
public:
	node(int newRnum =-1, int newIDnum =0,string newName ="",string newMail="", int newUnits =0, string newProgram ="", string newLevel ="", int newDsize=0);
	int getRnum() const;
	int getIDnum()const;
	string getName()const;
	string getMail()const;
	int getUnit()const;
	string getProgram()const;
	string getLevel()const;

	void setRnum(int newRnum);
	void setIDnum(int newIDnum);
	void setUnits(int newUnits);
	void setProgram(string newProgram);
	void setLevel(string newLevel);
	void setDsize(int size);
	void setName(string newName);
	void setMail(string newMail);
	string getAbsence();
	int getAbsencenum();
	string peekAbsence();
	void editAbsence(string newDate);
	void markAbsence();
	void setAbsence(string newDate);
private:
	int mRnum;
	int mIDnum;
	string mName;
	string mMail;
	int mUnits;
	int mDsize;
	int mMaxSize;
	string *mDates;
	string mProgram;
	string mLevel;
};