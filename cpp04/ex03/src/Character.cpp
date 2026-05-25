#include "Character.hpp"

Character::Character()
{
	for (size_t i = 0; i < 4; i++)
		_inventory[i] = NULL;
	materia_learned = 0;
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
		throw std::out_of_range("No space left on inventory");
	_inventory[materia_learned] = m;
	materia_learned++;
}

void	Character::unequip(int idx)
{
	if (materia_learned < idx)
		throw std::out_of_range("Idx out of range");
	_inventory[idx] = NULL;
	materia_learned--;
}

void	Character::use(int idx, ICharacter &target)
{
	cout << this->getName() << " attacked " << target.getName() << " with " << _inventory[idx]->getType() << endl;
}
