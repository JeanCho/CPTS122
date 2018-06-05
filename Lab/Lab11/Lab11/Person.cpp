#include "Person.h"

Person::Person(const string &newName = "", int newAge = 0, int newGender = 0, int newHeight = 0)
{
	mName = newName;
	mAge = newAge;
	mGender = newGender;
	mHeight = newHeight;
}

Person::~Person()
{
	cout << "Inside destructor of Person" << endl;
}
Person::Person(Person &copy)
{
	mName = copy.mName;
	mAge = copy.mAge;
	mHeight = copy.mHeight;
	mGender = copy.mGender;
}
string Person::getName() const
{
	return mName;
}
int Person::getAge() const
{
	return mAge;
}
int Person::getGender() const
{
	return mGender;
}
int Person::getHeight() const
{
	return mHeight;
}
void Person::setName(string newName)
{
	mName = newName;
}
void Person::setAge(int newAge)
{
	mAge = newAge;
}
void Person::setGender(int newGender)
{
	mGender = newGender;
}
void Person::setHeight(int newHeight)
{
	mHeight = newHeight;
}
ostream&operator<<(ostream&lhs, Person &rhs)
{
	cout << "Name : " << rhs.getName() << endl;
	cout << "Age : " << rhs.getAge() << endl;
	if (rhs.getGender() == 1)
	{
		cout << "Gender : Male" << endl;
	}
	else
	{
		cout << "Gender : Female" << endl;
	}
	cout << "Height : " << rhs.getHeight() << endl;
	return lhs;
}
istream&operator >> (istream&lhs, Person &rhs)
{
	string token;
	int num = 0;

	
	getline(lhs, token, ',');//name
	rhs.setName(token);
	getline(lhs, token, ',');//age
	rhs.setAge(stoi(token));
	getline(lhs, token, ',');//Gender
	rhs.setGender(stoi(token));
	getline(lhs, token);//height
	rhs.setHeight(stoi(token));


	return lhs;
}