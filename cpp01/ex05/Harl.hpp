#pragma once

#include <iostream>

using std::string;
using std::cout;
using std::endl;

class	Harl
{
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
	public:
		void	(Harl::*f[4])(void);
		void	complain(string level);
};
