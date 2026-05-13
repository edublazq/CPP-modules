#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const string &name);
		ScavTrap(const ScavTrap &toCopy);
		ScavTrap& operator=(const ScavTrap &toCopy);
		~ScavTrap();
		void	guardGate();
		void	attack(const string &target);
};

