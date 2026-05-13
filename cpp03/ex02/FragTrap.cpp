#include "FragTrap.hpp"

FragTrap::FragTrap()
	: ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	cout << "FragTrap constructor called" << endl;
}

FragTrap::~FragTrap()
{
	cout << "FragTrap destructor called" << endl;
}

FragTrap::FragTrap(const FragTrap &toCopy)
	:ClapTrap(toCopy)
{
	cout << "Copy FragTrap constructor called" << endl;
}

FragTrap::FragTrap(const string &name)
	:ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	cout << "FragTrap constructor called" << endl;
}

FragTrap&	FragTrap::operator=(const FragTrap &toCopy)
{
	if (this != &toCopy)
		ClapTrap::operator=(toCopy);
	return (*this);
}

void	FragTrap::highFivesGuys() const
{
	cout << "High Five Fella!" << endl;
}
