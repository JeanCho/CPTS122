#include"BSTNode.h"
Node::Node(string newName)
{
	mName = newName;
}

Node::~Node()
{
	cout << "BST Destructor" << endl;
}

string Node::getName()const
{
	return mName;
}

Node*&Node::getLeft()
{
	return mpLeft;
}
Node*&Node::getRight()
{
	return mpRight;
}
void Node::setName(string newName)
{
	mName = newName;
}
void Node::setLeft(Node *pLeft)
{
	mpLeft = pLeft;
}
void Node::setRight(Node *pRight)
{
	mpRight = pRight;
}

ostream & operator << (ostream &rhs, Node &lhs)
{
	cout << lhs.getName() << endl;
	return rhs;
}