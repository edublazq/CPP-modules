#include "Zombie.hpp"

Zombie* zombieHorde(int n, string name);

int	main(void)
{
	int		N = 5;
	Zombie	*horde;

	horde = zombieHorde(N, "Walker");

	for (int i = 0; i < N; i++)
	{
		std::cout << "Zombie " << i << ": ";
		horde[i].announce();
	}

	delete[] horde;

	return (0);
}
