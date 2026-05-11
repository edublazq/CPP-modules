#include "HumanB.hpp"

HumanB::HumanB()
{
	_name = "genericName2";
	_weapon = NULL;
	cout << "HumanB " << _name << " created" << std::endl;
}

HumanB::HumanB(const string &name)
{
	_name = name;
	_weapon = NULL;
	cout << "HumanB " << _name << " created" << std::endl;
}

HumanB::~HumanB()
{
	cout << "HumanB " << _name << " destroyed" << std::endl;
}

void	HumanB::attack() const
{
	if (_weapon == NULL)
		cout << _name << "attacked with no weapon!" << std::endl;
	else
		cout << _name << " attacked with " << _weapon->getType() << std::endl;
}
