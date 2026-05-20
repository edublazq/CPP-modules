#include "Cat.hpp"

Cat::Cat():
	Animal()
{
	_type = "Cat";
	_brain = new Brain();
	cout << "Cat constructor called" << endl;
}

Cat::Cat(const Cat &toCopy)
	: Animal(toCopy)
{
	_brain = new Brain(*toCopy._brain);
	cout << "Copy cat constructor called" << endl;
}

Cat::~Cat()
{
	delete _brain;
	cout << "Cat destructor called" << endl;
}

Cat&	Cat::operator=(const Cat &toCopy)
{
	if (this != &toCopy)
	{
		Animal::operator=(toCopy);
		delete _brain;
		_brain = new Brain(*toCopy._brain);
	}
	return (*this);
}

Brain	*Cat::getBrain() const
{
	return (_brain);
}

void	Cat::makeSound() const
{
	cout << "Miau miau i'm a cat" << endl;
}
