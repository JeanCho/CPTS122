#include "BST.h"

bool BST::insert(const string &newData)//public
{
	bool success = false;
	success = insertNode((this->mpRoot), newData);
	return success;
}
Node* BST::getRoot()
{
	return mpRoot;
}

BST::BST(Node *pRoot)
{
	mpRoot = pRoot;
}

//private
bool BST::insertNode(Node *&ptree, const string &newData)//pass refrence to pointer
{
	bool success = false;
	if (ptree == nullptr)//base case
	{
		Node *pMem = nullptr;
		pMem = new Node(newData);
		if (pMem != nullptr)
		{
			success = true;
			ptree = pMem;//dereference tree aloocate the node 
			return success;
		}


	}
	else if (newData > (ptree)->getName()) //recursive step
	{
		//go down right sbt
		insertNode(((ptree)->getRight()), newData);
	}
	else if (newData <(ptree)->getName())//left subtree
	{
		insertNode(((ptree)->getLeft()), newData);
	}
	else//duplicate
	{
		cout << "dup" << endl;
	}
}

BST::~BST()
{
	cout << "BST Destructor" << endl;

}
//void BST::printTree()
//{
//	Node *pCur = mpRoot;
//	while (mpRoot != nullptr)
//	{
//		cout << mpRoot;
//
//	}
//}
Node* BST::makeNode(string newName)
{
	Node *d;
	d= new Node(newName);

	return d;
}

//bool BST::insertNode(Node *&pTree, string newName)
//{
//	bool success = false;
//
//	if (pTree == nullptr)
//	{
//		Node *d = makeNode(newName);
//		if (d != nullptr)
//		{
//			pTree = d;
//			success = true;
//			return success;
//		}
//	}
//	else if (pTree->getName() > newName)
//	{
//		insertNode(pTree->getLeft(), newName);
//	}
//	else if (pTree->getName() < newName)
//	{
//		insertNode(pTree->getRight(), newName);
//	}
//	else //dupe
//	{
//		cout << "duplicate" << endl;
//	}
//}

void BST::inOrderTraversal(Node *pRoot)//inorder=nondecreasing order
{
	if (pRoot != nullptr)
	{
		inOrderTraversal(pRoot->getLeft());

		cout << pRoot;
		inOrderTraversal(pRoot->getRight());

	}
}
void BST::preOrderTraversal(Node *pRoot)
{
	if (pRoot != nullptr)
	{
		cout << pRoot;
		preOrderTraversal(pRoot->getLeft());
		preOrderTraversal(pRoot->getRight());

	}

	
}
