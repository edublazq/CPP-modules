#include "Array.hpp"
#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Please, introduce a number" << endl;
		return (1);
	}
	Array<unsigned int>	array(std::atoi(av[1]));
	for (unsigned int i = 0; i < array.size(); i++)
		array[i] = i;
	for (unsigned int i = 0; i < array.size(); i++)
		cout << "Array en idx " << i << " = " << array[i] << endl;
}
