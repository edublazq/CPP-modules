#include "easyfind.hpp"
#include <iostream>

using std::cout;
using std::endl;

int	main(void)
{
	int	nums[] = {2, 4, 6, 8, 100};
	std::list<int> myList(nums, nums + 5);
	try
	{
		cout << "He encontrado el elemento: " << *(easyfind(myList, 4)) << endl;
		cout << "He encontrado el elemento: " << *(easyfind(myList, 24)) << endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
