#include "WrongCat.hpp"

WrongCat::WrongCat():
	WrongAnimal()
{
	_type = "WrongCat";
	cout << "Cat constructor called" << endl;
}

WrongCat::WrongCat(const WrongCat &toCopy)
	: WrongAnimal(toCopy)
{
	cout << "Copy WrongCat constructor called" << endl;
}

WrongCat::~WrongCat()
{
	cout << "WrongCat destructor called" << endl;
}

WrongCat&	WrongCat::operator=(const WrongCat &toCopy)
{
	if (this != &toCopy)
		WrongAnimal::operator=(toCopy);
	return (*this);
}
