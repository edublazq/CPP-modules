#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	a("Pepe");
	ClapTrap	b("Juan");

	a.attack("Juan");
	b.takeDamage(3);

	b.beRepaired(2);

	b.attack("Pepe");
	a.takeDamage(5);

	a.beRepaired(4);

	a.attack("Juan");
	a.attack("Juan");
	a.attack("Juan");
	a.attack("Juan");
	a.attack("Juan");
	a.attack("Juan");
	a.attack("Juan");
	a.attack("Juan");

	a.beRepaired(1);

	return (0);
}