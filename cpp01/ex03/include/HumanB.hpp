#pragma once

#include "Weapon.hpp"

class HumanB
{
private:
	Weapon	*_weapon;
	string	_name;
public:
	HumanB();
	HumanB(const string &name);
	~HumanB();

	void	setWeapon(Weapon &newWeapon){ _weapon = &newWeapon; }
	void	setType(string type){ _weapon->setType(type); }
	void	attack() const;
};

