#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: " << av[0] << " <literal to convert>" << std::endl;
		return (EXIT_FAILURE);
	}
	string	toConvert(av[1]);
	ScalarConverter::convert(toConvert);
	return (EXIT_SUCCESS);
}
