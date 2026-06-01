#pragma once

#include <iostream>

using std::cout;
using std::string;
using std::endl;

class ClapTrap
{
	protected:
		string	_name;
		unsigned int		_hitPoints;
		unsigned int		_energyPoints;
		unsigned int		_attackDamage;
	public:
		ClapTrap();
		ClapTrap(const string &name);
		ClapTrap& operator=(const ClapTrap &toCopy);
		ClapTrap(const ClapTrap &toCopy);
		virtual ~ClapTrap();

		string	getName() const {return _name;}
		int		getHitPoints() const {return _hitPoints;}
		int		getEnergyPoints() const {return _energyPoints;}
		int		getAttackDamage() const {return _attackDamage;}

		virtual void	attack(const string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

