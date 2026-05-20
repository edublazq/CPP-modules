#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain	*_brain;
	public:
		Cat();
		Cat(const Cat &toCopy);
		~Cat();
		Cat& operator=(const Cat &toCopy);

		void	makeSound() const;
		Brain	*getBrain() const;
};

