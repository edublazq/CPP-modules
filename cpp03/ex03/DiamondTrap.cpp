#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
	: ClapTrap("Default")
{
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	cout << "DiamondTrap constructor called" << endl;
}

DiamondTrap::~DiamondTrap()
{
	cout << "DiamondTrap destructor called" << endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &toCopy)
:	ClapTrap(toCopy),
	FragTrap(toCopy),
	ScavTrap(toCopy)
{
	cout << "DiamondTrap copy constructor called" << endl;
}

DiamondTrap::DiamondTrap(const string &name)
:	ClapTrap(name + "_clap_name")
{
	cout << "DiamondTrap name constructor called" << endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &toCopy)
{
	if (this != &toCopy)
		ClapTrap::operator=(toCopy);
	return (*this);
}

void	DiamondTrap::whoAmI()
{
	cout << "name: " << _name << " claptrap name: " << ClapTrap::_name << endl;
}

void	DiamondTrap::attack(const string &target)
{
	ScavTrap::attack(target);
}

