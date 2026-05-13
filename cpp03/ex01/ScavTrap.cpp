#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	cout << "ScavTrap constructor called" << endl;
}

ScavTrap::ScavTrap(const ScavTrap &toCopy)
	: ClapTrap(toCopy)
{
	cout << "ScavTrap copy constructor called" << endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &toCopy)
{
	if (this != &toCopy)
		ClapTrap::operator=(toCopy);
	return (*this);
}

ScavTrap::ScavTrap(const string &name):
	ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	cout << "ScavTrap constructor called" << endl;
}

ScavTrap::~ScavTrap()
{
	cout << "ScavTrap destructor called" << endl;
}

void	ScavTrap::attack(const string &target)
{
	cout << "Scavtrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << endl;
}

void	ScavTrap::guardGate()
{
	cout << _name << " is now in Gate keeper mode" << endl;
}
