#pragma once
#include "Node.h"

class Tnode :public Node
{
public:
	Tnode(const string& newData = "",int newUnits=0);
	~Tnode();

	int getUnits();
	
	void setUnits(int newUnits);
	void printData();
private:
	int mUnits;
};
 