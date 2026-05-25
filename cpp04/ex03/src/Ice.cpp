#include "Ice.hpp"

Ice::Ice()
	: AMateria("Ice")
{
	cout << "Ice constructor called" << endl;
}

Ice::~Ice()
{
	cout << "Ice destructor called" << endl;
}

Ice::Ice(const Ice &other)
{
	_type = other._type;
}

Ice& Ice::operator=(const Ice &other)
{
	if (this != &other)
		_type = other._type;
	return (*this);
}

AMateria	*Ice::clone() const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter &target)
{
	cout << "* shoots an ice bolt at " << target.getName << " *" << endl;
}
