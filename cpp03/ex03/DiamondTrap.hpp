#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		string	_name;
	public:
		DiamondTrap();
		DiamondTrap(const DiamondTrap &toCopy);
		DiamondTrap(const string &name);
		DiamondTrap& operator=(const DiamondTrap &toCopy);
		~DiamondTrap();

		void	whoAmI();
		void	attack(const string &target);
};

