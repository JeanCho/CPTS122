#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
typedef enum boolean
{
	FALSE, TRUE
} Boolean;

typedef struct duration
{
	int seconds;
	int minutes;

}Duration;

//save data of music
typedef struct record
{
	char Artist[128];
	char Album[128];
	char sTitle[100];
	char Genre[100];
	Duration length;
	int Timeplayed;
	int Rating;


} Record;
 //linked list
typedef struct node
{
	Record data;
	struct Node *pNext;
	struct Node *pPrev;
}Node;

Boolean insertFront(Node **pList, Record pItem);
Node *makeNode(Record newData);
Boolean sort(Node **pList);
void printList(Node *pList, int choice);
Boolean deleteContact(Node **pList, char *sTitle);
Boolean editContact(Node *pList, char *artist);
Boolean loadContacts(FILE *infile, Node **pList);
Boolean editRating(Node *pList, char *sName);
int countChar(char* string, char character);
Boolean playSong(Node *pList);
void shuffle(Node *pList);
Boolean storeList(FILE *outfile, Node *pList);