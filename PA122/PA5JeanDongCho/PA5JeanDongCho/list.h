#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "DietPlan.h"
#include "ExercisePlan.h"
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::stringstream;

// This class defines a container for a list; it's a singly linked list
class List
{
public:
	List();                     // default constructor; will always set mpHead to NULL
	List(const List &copyList); // copy constructor - implicitly invoked copying a List object during construction of 
								// another List object, or when a List object is passed-by-value - must perform a deep copy, 
								// which means create new memory for each node copied!
	~List();                    // destructor - implicitly invoked when a List object leaves scope

	List & operator= (const List &rhs); // overloaded assignment operator - must perform a deep copy, which means
										// create new memory (from the heap) for each node copied!

										// getter
	ExercisePlan * getExerciseHead() const;     // returns a copy of the address stored in mpHead
	DietPlan * getDietHead() const;
									   // setter
	void setExerciseHead(ExercisePlan * const pNewHead); // modifies mpHead
	void setDietHead(DietPlan * const pNewHead); // modifies mpHead

	bool insertAtFront(int newData, string newName, string newDate,int check);     // inserts newData at the beginning or front of the list/ check :0=Dietplan, 1= exerciseplan
	//bool insertInOrder(int newSteps, string newName, string newDate);     // inserts newData in ascending (smallest to largest) order
	//bool insertAtEnd(int newSteps, string newName, string newDate);       // inserts newData at the end of the list

	bool isEmpty();                            // determines if the list is empty  

	int deleteAtFront();                       // deletes the node at the front of the list
	bool deleteNode(const int searchValue);    // deletes the node with data == searchValue
	int deleteAtEnd();                         // deletes the node at the end of the list

	void printList();                          // visits each node, print the node's data - we could also overload the stream insertion << operator to print the list

private:
	ExercisePlan *mEhead; // pointer to the start or head of the singly linked list
	DietPlan *mDhead;
					  // yes, we can make member functions private as well
	ExercisePlan * makeEplan(int newSteps, string newName, string newDate);    // will only call within insert functions
	DietPlan * makeDplan(int newGoal, string newName, string newDate);
	//void destroyList();                        // deletes each node to free memory; will call in the destructor
	//void destroyListHelper(ListNode * const pMem);    // we will use recursion to solve this problem!
};