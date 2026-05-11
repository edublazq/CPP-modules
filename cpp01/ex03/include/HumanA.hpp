#pragma once

#include "Weapon.hpp"

class HumanA
{
	private:
		Weapon	_weapon;
		string	_name;
	public:
		HumanA();
		HumanA(string name, Weapon &weapon);
		~HumanA();

		void	setWeapon(Weapon newWeapon){ _weapon = newWeapon; }
		void	setType(string type){ _weapon.setType(type); }
		void	attack() const;
};
