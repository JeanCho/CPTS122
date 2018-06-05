#pragma once
#include "BSTNode.h"

class BST
{

public:
	BST(Node *pRoot=nullptr);
	~BST();
	
	bool insert(const string &newData);
	void inOrderTraversal(Node *pRoot);
	void preOrderTraversal(Node *pRoot);
	Node *getRoot();
	Node* makeNode(string newName);
	//void printTree();
private:
	Node *mpRoot;
	//void inOrderTraversal(Node *pRoot);
	//void preOrderTraversal(Node *pRoot);
	bool insertNode(Node *&pTree,const string &newData);
};