#include "Cat.hpp"

Cat::Cat():
	Animal()
{
	_type = "Cat";
	cout << "Cat constructor called" << endl;
}

Cat::Cat(const Cat &toCopy)
	: Animal(toCopy)
{
	cout << "Copy cat constructor called" << endl;
}

Cat::~Cat()
{
	cout << "Cat destructor called" << endl;
}

Cat&	Cat::operator=(const Cat &toCopy)
{
	if (this != &toCopy)
		Animal::operator=(toCopy);
	return (*this);
}

void	Cat::makeSound() const
{
	cout << "Miau miau i'm a cat" << endl;
}
