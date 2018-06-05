#pragma once
#include "Mammal.h"

class Dog : public Mammal
{
public:
	Dog();
	~Dog();
	void Move() const;
	void Speak() const;
};