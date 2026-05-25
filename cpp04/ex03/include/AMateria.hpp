#pragma once

#include <iostream>
#include "ICharacter.hpp"

using std::string;
using std::cout;
using std::endl;

class AMateria
{
	protected:
		string	_type;
	public:
		AMateria(string const &type);
		string const &getType();

		virtual AMateria	*clone() const = 0;
		virtual void		use(ICharacter &target);
};

