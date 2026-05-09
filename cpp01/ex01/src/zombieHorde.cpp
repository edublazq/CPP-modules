#include "Zombie.hpp"

Zombie* zombieHorde(int n, string name)
{
	Zombie	*array = new Zombie[n];
	
	for (int i = 0; i < n; i++)
	{
		array[i].setName(name);
	}
	return (array);
}
