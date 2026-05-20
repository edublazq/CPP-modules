#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	cout << "WrongAnimal constructor called" << endl;
}

WrongAnimal::~WrongAnimal()
{
	cout << "WrongAnimal destructor called" << endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal &toCopy)
{
	if (this != &toCopy)
		_type = toCopy._type;
	return (*this);
}

WrongAnimal::WrongAnimal(const WrongAnimal &toCopy)
{
	_type = toCopy._type;
}

void	WrongAnimal::makeSound() const
{
	cout << "WrongAnimal having offspring sound" << endl;
}

string	WrongAnimal::getType() const
{
	return (_type);
}
