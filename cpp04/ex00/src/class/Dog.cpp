#include "Dog.hpp"

Dog::Dog()
	: Animal()
{
	_type = "Dog";
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

void	Dog::makeSound() const
{
	cout << "Guau guau i'm a Dog" << endl;
}
