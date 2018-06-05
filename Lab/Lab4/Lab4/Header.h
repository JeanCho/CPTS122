#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data
{
	int numv;
} Data;

typedef struct node
{

	Data data;
	struct node *pNext;
} Node;


Node *makenode(int num);
int insert(Node **plist, int num);
void printlist(Node *plist);



