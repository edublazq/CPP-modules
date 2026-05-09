#include "Zombie.hpp"

Zombie::Zombie()
{
	_name = "pirata";
	cout << "Creado zombie " << _name << std::endl;
}

Zombie::Zombie(string &name)
{
	_name = name;
	cout << "Creado zombie " << _name << std::endl;
}

void	Zombie::setName(string &name)
{
	_name = name;
}

Zombie::~Zombie()
{
	cout << "Destruido zombie " << _name << std::endl;
}

void	Zombie::announce(void) const
{
	cout << _name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}

