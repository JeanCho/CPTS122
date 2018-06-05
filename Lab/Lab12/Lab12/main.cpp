#include "Queue.h"

int main(void)
{
	List<int> l1;
	l1.insertAtFront(3);
	l1.insertAtFront(4);
	l1.print();
	Queue<int> q;
	q.enqueue(6);
	q.enqueue(7);

	q.enqueue(8);
	
	return 0;
}