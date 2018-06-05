#pragma once//dance-justice    young folks - peter 
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::string;
using std::endl;

template< class NODETYPE > class List;  // forward declaration

template<class NODETYPE>
class ListNode
{
	friend class List< NODETYPE >; // make List a friend now list can access the private data of listnode
public:
	ListNode(const NODETYPE &newData);  // copy constructor
	NODETYPE getData() const;      // return data in the node
private:
	NODETYPE data;                 // data
	ListNode< NODETYPE > *nextPtr; // next node in the list
};

template <class NODETYPE>
ListNode<NODETYPE>::ListNode(const NODETYPE &newData)
{
	data = newData;
	nextPtr = nullptr;
}
template <class NODETYPE>
NODETYPE ListNode<NODETYPE>::getData() const
{
	return data;
}



template< class NODETYPE >
class List
{
public:
	List();      // constructor
	~List();     // destructor
	void insertAtFront(const NODETYPE &newData);
	void insertAtBack(const NODETYPE &newData);
	bool removeFromFront(NODETYPE &removedData);
	bool removeFromBack(NODETYPE &removedData);
	bool isEmpty() const;
	void print() const;
private:
	ListNode< NODETYPE > *firstPtr;  // pointer to first node
	ListNode< NODETYPE > *lastPtr;   // pointer to last node

									 // Utility function to allocate a new node
	ListNode< NODETYPE > *getNewNode(const NODETYPE &newData) {
		return new ListNode<NODETYPE>(newData);
	}
};

template< class NODETYPE >
List<NODETYPE>::List()
{
	firstPtr = nullptr;
	lastPtr = nullptr;
}
template< class NODETYPE >
List<NODETYPE>::~List()
{
	cout << "List Destructor" << endl;
}

template< class NODETYPE >
bool List<NODETYPE>::isEmpty() const
{
	if (firstPtr == lastptr == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template< class NODETYPE >
void List<NODETYPE>::print() const
{
	ListNode< NODETYPE > *pCur = firstPtr;
	while (pCur != nullptr)
	{
		cout << "Data : " << pCur->getData() << endl;
		pCur = pCur->nextPtr;
	}
}


template<class NODETYPE>
void List<NODETYPE>::insertAtFront(const NODETYPE &newData)
{
	ListNode< NODETYPE > *pCur = firstPtr;
	ListNode< NODETYPE > *pMem = getNewNode(newData);

	if (pCur == nullptr)
	{
		lastPtr = firstPtr = pMem;
	
	}
	else
	{
		pMem->nextPtr = pCur;
		firstPtr = pMem;
	}

}

template<class NODETYPE>
void List<NODETYPE>::insertAtBack(const NODETYPE &newData)
{
	ListNode< NODETYPE > *pCur = lastPtr;
	ListNode< NODETYPE > *pMem = getNewNode(newData);
	if (pCur == nullptr)
	{
		lastPtr = firstPtr = pMem;
	}
	else
	{
		pCur->nextPtr = pMem;
		lastPtr = pMem;
	}
}

template<class NODETYPE>
bool List<NODETYPE>::removeFromFront(NODETYPE &removedData)
{
	bool result = false;
	ListNode< NODETYPE > *pCur = firstPtr;
	if (!isEmpty())
	{
		if (firstPtr == lastPtr)
		{
			delete pCur;
			firstPtr = lastPtr = nullptr;
			result = true;
		}
		else
		{
			firstPtr = pCur->nextPtr;
			delete pCur;
			result = true;
		}
	}
	return result;
}
template<class NODETYPE>
bool List<NODETYPE>::removeFromBack(NODETYPE &removedData)
{
	bool result = false;
	ListNode< NODETYPE > *pCur = firstPtr;
	ListNode< NODETYPE > *pPrev = nullptr;
	if (!isEmpty())
	{
		if (firstPtr == lastPtr)
		{
			delete pCur;
			firstPtr = lastPtr = nullptr;
			result = true;
		}
		else
		{
			while (pCur->nextPtr != nullptr)
			{
				pPrev = pCur;
				pCur = pCur->nextPtr;
			}
			delete pCur;
			lastPtr = pPrev;
			result = true;
		}
	}

	return result;
}