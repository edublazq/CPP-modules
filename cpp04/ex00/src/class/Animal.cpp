#include "Animal.hpp"

Animal::Animal()
{
	cout << "Animal constructor called" << endl;
}

Animal::~Animal()
{
	cout << "Animal destructor called" << endl;
}

Animal&	Animal::operator=(const Animal &toCopy)
{
	if (this != &toCopy)
		_type = toCopy._type;
	return (*this);
}

Animal::Animal(const Animal &toCopy)
{
	_type = toCopy._type;
}

void	Animal::makeSound()
{
	cout << "Animal having offspring sound" << endl;
}
