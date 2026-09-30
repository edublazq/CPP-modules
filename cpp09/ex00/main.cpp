#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	string	date, n_str;
	float	n;

	if (ac != 2)
		std::cerr << "Error: could not open file." << endl;

	try
	{
		BitcoinExchange	btc(av[1]);
		while (!std::cin.eof())
		{
			std::cout << "Introduce cuantos btc tienes: ";
			std::cin >> n_str;
			std::cout << "Introduce la fecha (formato: YYYY-MM-DD): ";
			std::cin >> date;
			try
			{
				n = btc.exchange(date, std::atof(n_str.c_str()));
				cout << date << " -> " << n << endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
	return (0);
}
