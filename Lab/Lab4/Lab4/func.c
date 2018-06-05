#include "Header.h"

Node *makenode(int num)
{
	Node* pMem = (Node *)malloc(sizeof(Node));

	if (pMem != NULL)
	{
		pMem->pNext = NULL;

		pMem->data.numv = num;
	}
	return pMem;
}

int insert(Node **plist, int num)
{
	Node *pMem = makenode(num);
	Node *pCur = NULL;
	int suc = 0;
	pCur = *plist;
	if (pMem != NULL)
	{
		if (plist == NULL)
		{
			*plist = pMem;
			suc = 1;
		}
		else
		{
			pMem->pNext = pCur;
			*plist = pMem;
			suc = 1;
		}
	}
	return suc;
}

void printlist(Node *plist)
{
	Node *pCur = NULL;
	int count = 0;
	pCur = plist;

	while (pCur != NULL)
	{
		printf("(%d).%d\n", count, pCur->data.numv);
		pCur = pCur->pNext;
	}
}

int merglist(Node**plist1, Node**plist2)
{
	Node* pCur1;
	Node* pCur2;
	Node* pPrev, *pTemp;
	pCur1 = *plist1;
	pCur2 = *plist2;

	while (pCur1 < pCur2)
	{
		pPrev = pCur1;
		pCur1 = pCur1->pNext;
		
	}
	pPrev->pNext = pCur2;
	pCur2->pNext = pCur1;
	
}