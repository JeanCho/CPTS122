#include "Header.h"
int isEmpty(QueueNode *pMem)
{
	return (pMem == NULL)?1:0;
	//return 1 if empty
}

Queue *makeQueue(void)
{
	Queue* pQ = (Queue*)malloc(sizeof(Queue));
	pQ->pHead = NULL;
	pQ->pTail = NULL;

	return pQ;

}

QueueNode *makeNode(Data newItem)
{
	// allocates space for a Node only-->two pointers!
	QueueNode *pMem = (QueueNode *)malloc(sizeof(QueueNode));

	if (pMem != NULL) // did malloc () fail?
	{
		pMem->pNext = NULL;
		// need to allocate space for the Data!
		pMem->pData = (Data *)malloc(sizeof(Data));

		if (pMem->pData != NULL) // struct Data allocated
		{
			//
			//pMem->pData->customerNumber = (int *)malloc(sizeof(int) *2);
			//pM/*em->pData->serviceTime = (int *)malloc(sizeof(int) * 2);
			//pMem->pData->totalTime = (int *)malloc(sizeof(int) * 2);*/
			
				
			pMem->pData->customerNumber = newItem.customerNumber;
			
			
			pMem->pData->serviceTime = newItem.serviceTime;
			

			pMem->pData->totalTime = newItem.totalTime;
			
		}
	}

	return pMem;
}

int enqueue(Queue *pQ, Data newItem)
{
	QueueNode *pMem = makeNode(newItem);
	int success = 0;

	if (isEmpty(pMem )!= 1) // memory was successfully allocated
	{
		if (pQ->pHead == NULL) // empty?
		{
			// it's an empty queue!
			// connect both the head and tail to the one new node
			pQ->pHead = pQ->pTail = pMem;
			success = 1;
		}
		else // not empty
		{
			pQ->pTail->pNext = pMem;
			pQ->pTail = pMem;
			success = 1;
		}
	}

	return success;
}
int dequeue(Queue *pQ)//find the customer number input value and delete that node
{
	int success = 0;
	QueueNode *pCur = NULL, *pPrev = NULL, *pTemp = NULL;
	pCur = pQ->pHead;
	if (isEmpty(pCur)!= 1)
	{


		
		if (pCur == pQ->pHead == pQ->pTail)
		{
			pTemp = pCur;
		
			pQ->pHead = pCur->pNext;
			pQ->pTail = NULL;	
			
			free(pTemp->pData);
			free(pTemp);
		}
		
		
		else
		{
			pTemp = pCur;
			pQ->pHead = pCur->pNext;

			pCur = pCur->pNext;
			
			free(pTemp->pData);
			free(pTemp);
		}
	}
	return success;
}



void printqueue(Queue *pQ)
{
	QueueNode* pCur = NULL;
	pCur = pQ->pHead;
	
	while (pCur != NULL)
	{
		printf("Customer number: %d/ serviceTime: %d/ TotalTime: %d\n", pCur->pData->customerNumber, pCur->pData->serviceTime, pCur->pData->totalTime);
		pCur = pCur->pNext;
	}
}

void set_totaltime(Queue *pQ)
{
	QueueNode* pCur = NULL;
	int totime = 0;
	pCur = pQ->pHead;
	while (pCur != NULL)
	{
		totime += pCur->pData->serviceTime;
		pCur->pData->totalTime = totime;
		pCur = pCur->pNext;
	}
}

