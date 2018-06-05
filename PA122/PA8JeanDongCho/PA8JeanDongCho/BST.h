#pragma once
#include "TransactionNode.h"

class BST
{
public:
	BST(Node * newRoot=nullptr);
	~BST();

	Node * getRoot();
	void setRoot(Node * newRoot);
	bool insert(string newData, int newUnit);
	void inOrderTraversal();
	void findSmallest(Tnode &Smallest);
	void findLargest(Tnode &Largest);
	
private:
	Node * mpRoot;
	bool insert(Node *&pRoot,string newData,int newUnit);
	void destroyTree(Node *&pRoot);//visit each node post  order
	void inOrderTraversal(Node *&pRoot);
	void findSmallest(Node *&pRoot, Tnode &Smallest);//transaction node
	void findLargest(Node *&pRoot, Tnode &Largest);
};
