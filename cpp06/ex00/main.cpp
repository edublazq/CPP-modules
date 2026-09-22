#include <cstdlib>
#include <iostream>
#include <string>

int	main(int ac, char **av)
{
	char *end;
	double d = strtod(av[1], &end);
	std::cout << "str end -> " << end << std::endl;
	std::cout << "d -> " << d << std::endl;
}
