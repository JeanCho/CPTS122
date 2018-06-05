#include "Dog.h"


Dog::Dog() 
{
	itsAge = 1;
	cout << "Doggy constructor" << endl;
}

Dog::~Dog()
{
	cout << "Dogg derstructor" << endl;
}



void Dog::Speak() const
{
	cout << "Dog Dog" << endl;
}

void Dog::Move() const
{
	cout << "paw paw" << endl;
}