#include "Zombie.hpp"

Zombie*	newZombie(std::string name);
void	randomChump(string name);

int	main(void)
{
	// Zombie en el heap
	Zombie *heapZombie = newZombie("Heapy");
	heapZombie->announce();

	std::cout << std::endl;

	// Zombie en el stack
	randomChump("Stacky");

	std::cout << std::endl;

	// Liberamos memoria del heap
	delete heapZombie;

	return (0);
}
