#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const FragTrap &toCopy);
		FragTrap(const string &name);
		FragTrap& operator=(const FragTrap &toCopy);
		~FragTrap();

		void	highFivesGuys(void) const;
};

