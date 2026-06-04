#include "AMateria.hpp"

AMateria::AMateria(string const &type)
	: _type(type)
{}

string	const &AMateria::getType() { return (_type); }

void	AMateria::use(ICharacter &target)
{
	cout << target.getName() << " was attacked using " << this->getType() << endl;
}
