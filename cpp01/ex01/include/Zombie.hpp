#pragma once

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;

class Zombie
{
	private:
		string	_name;
	public:
		Zombie();
		Zombie(string &name);
		~Zombie();

		void	setName(string &name);

		void	announce(void) const;
};
