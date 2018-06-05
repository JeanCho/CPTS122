#include "Node.h"

Node::Node(const string& newData)
{
	mData = newData;
	mPleft = nullptr;
	mPright = nullptr;
}
Node::~Node()
{
	cout << "Node destroyed" << endl;
	
}
string Node::getData() const
{
	return mData;
}
Node *&Node::getLeftP()
{
	return mPleft;
}
Node *&Node::getRightP()
{
	return mPright;
}

void Node::setData(const string &newData)
{
	mData = newData;
}
void Node::setLeft(Node* const newLeft)
{
	mPleft = newLeft;
}
void Node::setRight(Node* const newRight)
{
	mPright = newRight;
}

void Node::printData()
{
	cout << "Data : " << mData << endl;
}