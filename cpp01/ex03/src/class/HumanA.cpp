#include "HumanA.hpp"

HumanA::HumanA()
{
	_weapon = Weapon();
	_name = "genericName";
	cout << "HumanA created with " << _weapon.getType() << std::endl;
}

HumanA::HumanA(string name, Weapon &weapon)
{
	_name = name;
	_weapon = weapon;
	cout << "HumanA created with " << _weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
	cout << "HumanA destroyed" << std::endl;
}

void	HumanA::attack() const
{
	cout << _name << " attack with their " << _weapon.getType();
}
