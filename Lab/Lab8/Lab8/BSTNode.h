#pragma once
#include <iostream>
#include <string>


using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::ostream;

class Node
{
public:
	Node(string newName="");
	~Node();
	string getName()const;
	Node *&getLeft();
	Node *&getRight();
	void setName(string newName);
	void setLeft(Node *pLeft);
	void setRight(Node *pRight);
private:
	string mName;
	Node *mpLeft;
	Node*mpRight;

};

ostream & operator << (ostream &rhs, Node &lhs);
