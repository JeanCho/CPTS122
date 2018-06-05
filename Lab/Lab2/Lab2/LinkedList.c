#include "LinkedList.h"


// inserts an item at the front of the list
Boolean insertFront(Node **pList,Contact pItem)
{
	Node *pMem = NULL;
	int success = 0;

	// heap memory - up to programmer to manage
	pMem = (Node *) malloc(sizeof (Node)); // 104 bytes

	// did malloc () fail? Null ptr
	if (pMem != NULL)
	{
		success = 1;

		pMem->pNext = NULL;
		pMem->data = pItem;

		if (*pList == NULL) // dealing with an empty list!
		{
			(*pList) = pMem;
		}
		else // // not dealing with empty list
		{
			pMem->pNext = *pList;
			*pList = pMem;
		}
	}

	return TRUE;
}

// tries to allocate space for a Node on the heap
// initializes the Node with the item passed in, sets the next pointer to NULL
// returns a pointer to the beginning of the allocated block
Node *makeNode(Contact newData)
{
	Node *pMem = NULL;

	pMem = (Node *) malloc(sizeof (Node)); // allocate space on heap

	if (pMem != NULL) // malloc succeeded
	{
		// init memory
		pMem->pNext = NULL;
		pMem->data = newData;
	}

	return pMem;
}


// This function inserts items in alphabetical A - Z order.
// The case of the character matters! 'a' > 'A'
Boolean insertOrder(Node **pList, Contact newData)
{
	int success = 0;
	Node *pMem = NULL, *pPrev = NULL, *pCur = NULL;

	pCur = *pList; // set to first node in list, if it exists

	pMem = makeNode(newData);

	if (pMem != NULL) // was memory allocated?
	{
		success = 1;

		// where to insert in order?
		while ((pCur != NULL) && (strcmp (newData.name,pCur->data.name) > 0)) // short circuit?
		{
			// allow for us to advance through list
			pPrev = pCur;
			pCur = pCur->pNext;
		}

		// found the place to insert

		if (pPrev != NULL) // 
		{
			// not inserting at the front
			pPrev->pNext = pMem;
			pMem->pNext = pCur;
		}
		else // inserting at front
		{
			pMem->pNext = pCur; // *pList
			*pList = pMem;
		}
	}

	return TRUE;
}

// print out all of the items in the list
void printList(Node *pList)
{
	printf("--> ");
	while (pList != NULL)
	{
		printf("%s/%s/%s/%s --> ", pList->data.name,pList->data.phone,pList->data.email,pList->data.title);
		pList = pList->pNext;
	}
	putchar('\n');
}



Boolean deleteContact(Node **pList, Contact searchContact)
{
	int success = 0;
	Node *pCur = NULL;
	Node *pPrev = NULL;
	Node *pTemp = NULL;

	pCur = *pList;

	
	while ((pCur != NULL) &&strcmp(searchContact.name,pCur->data.name) == 0)
	{
		pPrev = pCur;
		pCur = pCur->pNext;
		
	}

	if (pPrev != NULL) // 
	{
		// not inserting at the front
		pPrev->pNext = pCur->pNext;
		free(pCur);
	}
	else // inserting at front
	{
		pMem->pNext = pCur->; // *pList
		*pList = pMem;
	}
	
}