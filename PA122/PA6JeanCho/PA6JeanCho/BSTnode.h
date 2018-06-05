#pragma once
#include <iostream>
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
	//constructor
	Node(char alpha='\0', const string &newData = "");

	//gether
	string getData() const;
	char getAlpha() const;
	Node * &getLeft();
	Node * &getRight();

	//setter
	void setData(const string &newData);
	void setAlpha(const char newAplha);
	void setLeft(Node * const pNewLeft);
	void setRight(Node * const pNewRight);



private:
	string mData;
	char mAlpha;

	Node *pLeft;
	Node *pRight;
};
