#include "Dog.hpp"

Dog::Dog()
	: Animal()
{
	_type = "Dog";
	_brain = new Brain();
	cout << "Dog constructor called" << endl;
}

Dog::~Dog()
{
	delete _brain;
	cout << "Dog destructor called" << endl;
}

Dog::Dog(const Dog &toCopy)
	: Animal(toCopy)
{
	_brain = new Brain(*toCopy._brain);
	cout << "Dog copy constructor called" << endl;
}

Dog&	Dog::operator=(const Dog &toCopy)
{
	if (this != &toCopy)
	{
		Animal::operator=(toCopy);
		delete _brain;
		_brain = new Brain(*toCopy._brain);
	}
	return (*this);
}

Brain	*Dog::getBrain() const
{
	return (_brain);
}

void	Dog::makeSound() const
{
	cout << "Guau guau i'm a Dog" << endl;
}
