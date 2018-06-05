#include "Header.h"

int main(void)
{	
	Node *list1 = NULL;
	Node *list2 = NULL;

	

	insert(&list1, 4);
	insert(&list1, 3);
	insert(&list1, 2);
	insert(&list1, 1);

	printlist(list1);


	insert(&list2, 8);
	insert(&list2, 7);
	insert(&list2, 6);
	insert(&list2, 0);



}