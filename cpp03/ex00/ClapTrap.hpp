#pragma once

#include <iostream>

using std::cout;
using std::string;
using std::endl;

class ClapTrap
{
	private:
		string	_name;
		unsigned int		_hitPoints;
		unsigned int		_energyPoints;
		unsigned int		_attackDamage;
	public:
		ClapTrap();
		ClapTrap(const string &name);
		ClapTrap& operator=(const ClapTrap &toCopy);
		ClapTrap(const ClapTrap &toCopy);
		~ClapTrap();

		string	getName() {return _name;}
		int		getHitPoints() {return _hitPoints;}
		int		getEnergyPoints() {return _energyPoints;}
		int		getAttackDamage() {return _attackDamage;}

		void	attack(const string &target) const;
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

