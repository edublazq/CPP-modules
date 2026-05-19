#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat &toCopy);
		~Cat();
		Cat& operator=(const Cat &toCopy);

		void	makeSound() const;
};

