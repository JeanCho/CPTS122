#pragma once
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;
using std::istream;
class  Person
{
public:
	Person(const string &newName = "", int newAge = 0, int newGender = 0, int newHeight = 0);
	~Person();
	Person(Person &copy);
	string getName() const;
	int getAge() const;
	int getGender() const;
	int getHeight() const;
	void setName(string newName);
	void setAge(int newAge);
	void setGender(int newGender);
	void setHeight(int newHeight);

protected:
	string mName;
	int mAge;//1 ==male 2==female
	int mGender;
	int mHeight;
};


ostream&operator<<(ostream&lhs, Person &rhs);
istream&operator >>(istream&lhs, Person &rhs);
