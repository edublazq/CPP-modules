#include "Harl.hpp"

void	Harl::debug()
{
	cout << "I  love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << endl;
}

void	Harl::info()
{
	cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << endl;
}

void	Harl::warning()
{
	cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << endl;
}

void	Harl::error()
{
	cout << "This is unacceptable! I want to speak to the manager now." << endl;
}

void	Harl::complain(string level)
{
	int	lev_switch = -1;

	if (level == "DEBUG")
		lev_switch = 0;
	if (level == "INFO")
		lev_switch = 1;
	if (level == "WARNING")
		lev_switch = 2;
	if (level == "ERROR")
		lev_switch = 3;
	switch(lev_switch)
	{
		case 0:
			debug();
			//fall through
		case 1:
			info();
			//fall through
		case 2:
			warning();
			//fall through
		case 3:
			error();
			break ;
		default:
			cout << "Probably complaining about insignificant problems..." << endl;
	}
}