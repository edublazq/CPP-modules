#include "Dog.hpp"

Dog::Dog()
	: Animal()
{
	cout << "Dog constructor called" << endl;
}

Dog::~Dog()
{
	cout << "Dog destructor called" << endl;
}

Dog::Dog(const Dog &toCopy)
	: Animal(toCopy)
{
}

Dog&	Dog::operator=(const Dog &toCopy)
{
	if (this != &toCopy)
		Animal::operator=(toCopy);
	return (*this);
}
