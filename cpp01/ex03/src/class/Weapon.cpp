#include "Weapon.hpp"

Weapon::Weapon()
{
	_type = "random";
	cout << GREEN <<"Weapon created" << RESET << std::endl;
}

Weapon::Weapon(const string type)
{
	_type = type;
	cout << GREEN <<"Weapon created" << RESET << std::endl;
}

Weapon::~Weapon()
{
	cout << RED << "Weapon destructed" << RESET << std::endl;
}

string	Weapon::getType() const
{
	return (_type);
}

void	Weapon::setType(string type)
{
	_type = type;
}
