#include "BST.h"

BST::BST(Node * newRoot)
{
	mpRoot = newRoot;
}
BST::~BST()
{
	destroyTree(mpRoot);
	cout << "Tree destroyed" << endl;
}
Node * BST::getRoot()
{
	return mpRoot;
}
void  BST::setRoot(Node * newRoot)
{
	mpRoot = newRoot;
}

bool BST::insert(string newData, int newUnit)//public
{
	return insert(mpRoot, newData, newUnit);
}
void BST::inOrderTraversal()
{
	inOrderTraversal(this->mpRoot);
}
void BST::findSmallest(Tnode &Smallest)//public
{
	findSmallest(this->mpRoot, Smallest);
}
void BST::findLargest(Tnode &Largest)
{
	findLargest(this->mpRoot, Largest);
}


bool BST::insert(Node *&pRoot, string newData, int newUnit)
{
	bool success = false;

	if (pRoot == nullptr) // base case?
	{
		Tnode *pMem = nullptr;

		pMem = new Tnode(newData,newUnit);

		if (pMem != nullptr)
		{
			success = true;
			pRoot = pMem;
		}
	}
	else if (newUnit > ((Tnode*)pRoot)->getUnits())// recursive step, downcast
	{
		// go down right subtree
		success = insert(pRoot->getRightP(),newData,newUnit);
	}
	else if (newUnit <  ((Tnode*)pRoot)->getUnits())// left subtree
	{
		success = insert(pRoot->getLeftP(), newData, newUnit);
	}
	else // duplicate
	{
		cout << "dup" << endl;
	}

	return success;
}

void BST::destroyTree(Node *&pRoot)//destroy recursivelt in post order
{
	if (pRoot != nullptr)
	{
		if (pRoot->getLeftP() != nullptr)
		{
			destroyTree(pRoot->getLeftP());
		}
		if (pRoot->getRightP() != nullptr)
		{
			destroyTree(pRoot->getRightP());
		}
	
		delete pRoot;
		
	}
	
	
}
void BST::inOrderTraversal(Node *&pRoot)
{
	if (pRoot != nullptr)
	{
		inOrderTraversal(pRoot->getLeftP());
		cout << "Data : " << pRoot->getData() << endl;
		cout << "Unit : " << ((Tnode*)pRoot)->getUnits() << endl;
		inOrderTraversal(pRoot->getRightP());
	}
}
void BST::findSmallest(Node *&pRoot, Tnode &Smallest)//transaction node
{
	if (pRoot != nullptr)
	{
		Smallest.setData(pRoot->getData());
		Smallest.setUnits(((Tnode*)pRoot)->getUnits());
		findSmallest(pRoot->getLeftP(), Smallest);
		
	}
}
void BST::findLargest(Node *&pRoot, Tnode &Largest)
{
	if (pRoot != nullptr)
	{
		Largest.setData(pRoot->getData());
		Largest.setUnits(((Tnode*)pRoot)->getUnits());
		findLargest(pRoot->getRightP(), Largest);

	}
}