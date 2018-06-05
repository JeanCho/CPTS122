#include "TransactionNode.h"
Tnode::Tnode(const string& newData ,int newUnits ) :Node(newData)
{
	mUnits = newUnits;
}
Tnode::~Tnode()
{
	cout << "Tnode destructor" << endl;
}

int Tnode::getUnits()
{
	return mUnits;
}
void Tnode::setUnits(int newUnits)
{
	mUnits = newUnits;
}
void Tnode::printData()
{
	cout << "Data : " << mData << endl;
	cout << "Units : " << mUnits << endl;
	
}