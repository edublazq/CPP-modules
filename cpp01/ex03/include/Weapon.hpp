#pragma once

#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"

using std::string;
using std::cout;

class Weapon
{
	private:
		string	_type;
	public:
		Weapon();
		Weapon(const string type);
		~Weapon();

		void	setType(string type);
		string	getType(void) const;
};
