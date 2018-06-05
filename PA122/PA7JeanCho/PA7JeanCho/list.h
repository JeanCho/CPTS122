#pragma once
#include "node.h"
using std::to_string;

class list
{
public:
	list(int newsize = 0);
	~list();

	bool push(node &newItem);
	bool pop();
	bool peek(node &item);
	bool isEmpty();

	void loadClassList();
	void loadMasterList();
	void storeMasterList();
	void printList();
	void printMenu();
	void report();
	void markAbsence();
	void editAbsence();

private:
	int mSize;
	int mMaxsize;
	node *mTop;
	void loadList(ifstream &Input);

	ifstream mInput;
	ifstream mMasterIn;
	ofstream mMasterOut;

};