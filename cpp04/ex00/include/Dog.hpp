#pragma once

#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog &toCopy);
		Dog& operator=(const Dog &toCopy);
		~Dog();

		void	makeSound();
};

