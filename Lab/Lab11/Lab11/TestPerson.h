#pragma once
#include <iostream>
#include <string>
#include "Person.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;
using std::istream;

class TestPerson : public Person
{
public:
	TestPerson(const std::string &newName = "", int newAge = 0, int newGender = 0, int newHeight = 0);
	~TestPerson();
private:
};
