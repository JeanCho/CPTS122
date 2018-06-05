#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct data
{
	int customerNumber; // Unique identifier; starts at 1; after 24 hours should be reset to 1
	int serviceTime;   // Random time; varies between express and normal lanes; units in minutes
	int totalTime;     // totalTime = serviceTime + sum of serviceTimes of customers in line before this customer; units in minutes
} Data; // This memory needs to be allocated on the heap!

typedef struct queueNode
{
	Data *pData;    // The memory for Data will need to be allocated on the heap as well!

	struct queueNode *pNext;
} QueueNode;

typedef struct queue
{
	QueueNode *pHead;
	QueueNode *pTail;
} Queue;

QueueNode *makeNode(Data newItem);
int enqueue(Queue *pQ, Data newItem);
void printqueue(Queue *pQ);
Queue *makeQueue(void);
int isEmpty(QueueNode *pMem);
void set_totaltime(Queue *pQ);
int dequeue(Queue *pQ);