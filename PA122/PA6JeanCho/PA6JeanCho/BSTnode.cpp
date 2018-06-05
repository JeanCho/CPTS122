#include "BSTnode.h"

Node::Node(char alpha , const string &newData )
{
	this->mData = newData;
	this->mAlpha = alpha;
	this->pLeft = nullptr;
	this->pRight = nullptr;
}

string Node::getData() const
{
	return mData;
}
char Node::getAlpha() const
{
	return mAlpha;
}
void Node::setData(const string &newData)
{
	this->mData = newData;
}
void Node::setAlpha(const char newAplha)
{
	this->mAlpha = newAplha;
}


Node * &Node::getLeft()
{
	return this->pLeft;
}

void Node::setLeft(Node * const pNewLeft)
{
	this->pLeft = pNewLeft;
}

Node * &Node::getRight()
{
	return this->pRight;
}

void Node::setRight(Node * const pNewRight)
{
	this->pRight = pNewRight;
}
