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

void	ClapTrap::attack(const string &target)
{
	if (_hitPoints == 0 || _energyPoints == 0)
	{
		cout << "ClapTrap " << _name << " can't attack, no HP or energy left!" << endl;
		return;
	}
	_energyPoints--;
	cout << "Claptrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount >= _hitPoints)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
	cout << "ClapTrap " << _name << " takes " << amount << " points of damage! HP: " << _hitPoints << endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0 || _energyPoints == 0)
	{
		cout << "ClapTrap " << _name << " can't repair, no HP or energy left!" << endl;
		return;
	}
	_energyPoints--;
	_hitPoints += amount;
	cout << "ClapTrap " << _name << " repairs itself for " << amount << " HP! HP: " << _hitPoints << endl;
}
