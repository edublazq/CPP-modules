#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain	*_brain;
	public:
		Dog();
		Dog(const Dog &toCopy);
		Dog& operator=(const Dog &toCopy);
		~Dog();

		void	makeSound() const;
		Brain	*getBrain() const;
};

