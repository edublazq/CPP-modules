#pragma once

#include "ICharacter.hpp"
#include <stdexcept>

class Character : public ICharacter
{
	private:
		string		_name;
		AMateria	*_inventory[4];
		size_t		materia_learned;
	public:
		Character();
		Character(const string &name);
		Character(const Character &toCopy);
		Character& operator=(const Character &toCopy);
		~Character();

		string const	&getName() const;
		void			equip(AMateria *m);
		void			unequip(int idx);
		void			use(int idx, ICharacter &target);
};

