#include "Header.h"

int main(void)
{
	
	Data* nocustomer = (Data *)malloc(sizeof(Data));
	Data* excustomer = (Data *)malloc(sizeof(Data));
	Queue* express = makeQueue();
	Queue* normal = makeQueue();
	QueueNode* pCur = NULL;
	int exf = 0, nof = 0,exsrvt=0,nosrvt=0, exc=0,noc=0, clock = 0,min=0;
	int nocnum = 1, excnum = 1, n = 0;
	int tnextcNo = 0, tnextcEx = 0;
	int arvtNo[25] = { 0 }, arvtEx[1440] = { 0 }; //array that save the arrived time of customer

	
	printf("How many minutes you will stay in mart?:\n");
	scanf("%d", &n);

	exf = rand() % 5 + 1;// time of first express line customer arriving rand 1-5
	nof = rand() % 6 + 3; // " of first normal line customer
	exc = exf; //time for next arriving express customer
	noc = nof;
	clock = 0;
	for (min = 1; min < n+1; min++)
	{
		//exc = exf+ rand() % 30 + min; //arivial time of customer
		//noc = nof+ rand() % 30 + min;
		exsrvt = rand()%5 +1;//service time of customer
		nosrvt = rand()%6 +3;

		if (min % 1440 == 0)//when its been 24hour reset customer number to 1
		{
			nocnum = 1;
			excnum = 1;
		}

		if (min == noc)//if the time match the customer's arriving time
		{
			printf("Customer arrived to normal line, Time:%d\n",min);
			tnextcNo = rand() % 6+3; //arivial time of next customer 3-8 min
			noc = noc + tnextcNo;
			arvtNo[nocnum] = min;
			nocustomer->customerNumber = nocnum;
			nocustomer->serviceTime = nosrvt;
			nocustomer->totalTime = 0;
			enqueue(normal, *nocustomer);
			nocnum += 1;
		}
		if (min == exc)
		{
			printf("Customer arrived to express line, Time:%d\n",min);
			tnextcEx = rand() % 5 + 1;
			exc = exc + tnextcEx;
			arvtEx[excnum] = min;
			excustomer->customerNumber = excnum;
			excustomer->serviceTime = exsrvt;
			excustomer->totalTime = 0;
			enqueue(express, *excustomer);
			excnum += 1;
		}
		pCur = normal->pHead;
		if (pCur != NULL)
		{
			if (arvtNo[pCur->pData->customerNumber] + pCur->pData->serviceTime <= min)
			{
				printf("Normal line Custonmer%d left the store\nArrived time: %d, left at :%d\n", pCur->pData->customerNumber, arvtNo[pCur->pData->customerNumber],min);
				printf("Normalline total time: %d\n\n", normal->pTail->pData->totalTime);

				dequeue(normal);
			}
			
		}
		pCur = express->pHead;
		if (pCur != NULL)
		{
			if (arvtEx[pCur->pData->customerNumber] + pCur->pData->serviceTime <= min)
			{
				printf("Express line Custonmer%d left the store\nArrived time: %d, left at :%d\n", pCur->pData->customerNumber, arvtEx[pCur->pData->customerNumber],min);
				printf("Expressline total time: %d\n\n", express->pTail->pData->totalTime);

				dequeue(express);
			}
		}

		if (min % 10 == 0)//every 10 min print the que
		{
			printf("%d minute\n\n", min);
			if (express->pHead != NULL)
			{
				set_totaltime(express);
				printf("Expressline total time: %d\n", express->pTail->pData->totalTime);
				printf("Expressline situation:\n");
				printqueue(express);
				printf("\n");
			}
			if (normal->pHead != NULL)
			{
				set_totaltime(normal);
				printf("Normalline total time: %d\n", normal->pTail->pData->totalTime);
				printf("Normalline stuiation:\n");
				printqueue(normal);
				printf("\n");
			}
			if (express->pHead == NULL)
			{
				printf("The express line is clear, Total time: 0 \n");
			}
			if (normal->pHead == NULL)
			{
				printf("The express line is clear, Total time : 0 \n");
			}

			
			printf("\n\n");

		}
		
		
	}

}