#include "iter.hpp"
#include <iostream>
#include <string>

template <typename T>
void	print(T &elem)
{
	std::cout << elem << " ";
}

void	printInt(int &elem)
{
	std::cout << elem << " ";
}

void	doubleInt(int &elem)
{
	elem *= 2;
}

struct PrintFunctor
{
	void	operator()(std::string &elem)
	{
		std::cout << "[" << elem << "] ";
	}
};

int	main(void)
{
	std::cout << "-- int array with function pointer --" << std::endl;
	int	ints[] = {1, 2, 3, 4, 5};
	int	len = sizeof(ints) / sizeof(ints[0]);
	iter(ints, len, printInt);
	std::cout << std::endl;

	std::cout << "-- int array, modify in place (double) --" << std::endl;
	iter(ints, len, doubleInt);
	iter(ints, len, printInt);
	std::cout << std::endl;

	std::cout << "-- string array with functor --" << std::endl;
	std::string	strs[] = {"hello", "world", "42"};
	int	slen = sizeof(strs) / sizeof(strs[0]);
	PrintFunctor	pf;
	iter(strs, slen, pf);
	std::cout << std::endl;

	std::cout << "-- templated print function --" << std::endl;
	iter(strs, slen, print<std::string>);
	std::cout << std::endl;

	std::cout << "-- const int array --" << std::endl;
	const int	cints[] = {10, 20, 30};
	int	clen = sizeof(cints) / sizeof(cints[0]);
	iter(cints, clen, printInt);
	std::cout << std::endl;

	return (0);
}
