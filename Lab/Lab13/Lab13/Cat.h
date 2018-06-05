#pragma once
#include "Mammal.h"

class Cat : public Mammal
{
public:
	Cat();
	~Cat();
	void Move() const;
	void Speak() const;
}; 
