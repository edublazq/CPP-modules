#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: _name("Standard claptrap"),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0)
{
	cout << "ClapTrap constructor called" << endl;
}

ClapTrap::~ClapTrap()
{
	cout << "ClapTrap destructor called" << endl;
}

ClapTrap::ClapTrap(const string &name)
	: _name(name),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0)
{
	cout << "ClapTrap constructor called" << endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &claptrap)
{
	_name = claptrap._name;
	_hitPoints = claptrap._hitPoints;
	_energyPoints = claptrap._energyPoints;
	_attackDamage = claptrap._attackDamage;
	return (*this);
}

ClapTrap::ClapTrap(const ClapTrap &toCopy)
{
	_name = toCopy._name;
	_hitPoints = toCopy._hitPoints;
	_energyPoints = toCopy._energyPoints;
	_attackDamage = toCopy._attackDamage;
	cout << "Copy ClapTrap constructor called" << endl;
}

void	ClapTrap::attack(const string &target) const
{
	cout << "Claptrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	_energyPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	_energyPoints += amount;
}
