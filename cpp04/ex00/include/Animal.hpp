#pragma once

#include <iostream>

using std::string;
using std::endl;
using std::cout;

class Animal
{
	protected:
		string	_type;
	public:
		Animal();
		Animal(const Animal &toCopy);
		Animal& operator=(const Animal &toCopy);
		~Animal();

		virtual void	makeSound();
};

