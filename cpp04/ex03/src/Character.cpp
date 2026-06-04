#include "Character.hpp"

Character::Character()
{
	for (size_t i = 0; i < 4; i++)
		_inventory[i] = NULL;
	materia_learned = 0;
	_name = "std_name";
}

Character::Character(const string &name)
{
	for (size_t i = 0; i < 4; i++)
		_inventory[i] = NULL;
	materia_learned = 0;
	_name = name;
}

Character::Character(const Character &toCopy) : ICharacter(toCopy) {}

Character &Character::operator=(const Character &toCopy)
{
	if (this != &toCopy)
		ICharacter::operator=(toCopy);
	return (*this);
}

Character::~Character() {}

string const	&Character::getName() const
{
	return (_name);
}

void	Character::equip(AMateria *m)
{
	if (!m || materia_learned > 3)
	{
		std::cerr << "No space left on inventory" << endl;
		return ;
	}
	_inventory[materia_learned] = m;
	materia_learned++;
}

void	Character::unequip(int idx)
{
	if (materia_learned < (size_t)idx)
	{
		std::cerr << "No space left on inventory" << endl;
		return ;
	}
	_inventory[idx] = NULL;
	materia_learned--;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx > 3 || idx < 0 || !_inventory[idx])
	{
		std::cerr << "invalid index" << endl;
		return ;
	}
	cout << this->getName() << " attacked " << target.getName() << " with " << _inventory[idx]->getType() << endl;
}
