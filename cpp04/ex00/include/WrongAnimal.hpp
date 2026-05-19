#pragma once

#include <iostream>

using std::string;
using std::endl;
using std::cout;

class WrongAnimal
{
	protected:
		string	_type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &toCopy);
		WrongAnimal& operator=(const WrongAnimal &toCopy);
		virtual ~WrongAnimal();

		void	makeSound() const;
		string	getType() const;
};

