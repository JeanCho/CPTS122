#pragma once
#include<iostream>
#include <fstream>
#include <string>
using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;

class Node
{
public:
	Node(const string& newData = "");
	virtual ~Node();
	string getData() const;
	Node *&getLeftP();
	Node *&getRightP();

	void setData(const string &newData);
	void setLeft(Node* const newLeft);
	void setRight(Node* const newRight);

	virtual void printData()=0;
protected:
	string mData;
	Node* mPleft;
	Node* mPright;
};