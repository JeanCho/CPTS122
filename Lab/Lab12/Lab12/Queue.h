#pragma once
#include "list.h"

template<class NODETYPE>
class Queue : private List<NODETYPE>
{
public:
	Queue():List(){}
	//Queue: private List();
	//~Queue: private ~List();
	void enqueue(const NODETYPE &newData)
	{
		insertAtFront(newData);
	}
	void dequeue()
	{
		List::removeFromBack();
	}

};

//template<class NODETYPE>
//Queue<NODETYPE>::Queue():List()
//{}

//template<class NODETYPE>
//Queue<NODETYPE>::~Queue()
//{
//	cout << "Queue Destructor" << endl;
//}
//
//template<class NODETYPE>
//bool Queue<NODETYPE>::enqueue(const NODETYPE &newData)
//{
//	
//}
