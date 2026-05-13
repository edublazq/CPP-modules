#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "========== CLAPTRAP ==========" << std::endl;

	ClapTrap	clap("Basic");

	clap.attack("target");
	clap.takeDamage(5);
	clap.beRepaired(3);

	std::cout << std::endl;

	std::cout << "========== SCAVTRAP ==========" << std::endl;

	ScavTrap	scav("Guardian");

	scav.attack("enemy");
	scav.takeDamage(30);
	scav.beRepaired(10);
	scav.guardGate();

	std::cout << std::endl;

	std::cout << "========== FRAGTRAP ==========" << std::endl;

	FragTrap	frag("Destroyer");

	frag.attack("boss");
	frag.takeDamage(40);
	frag.beRepaired(20);
	frag.highFivesGuys();

	std::cout << std::endl;

	std::cout << "========== COPY TEST ==========" << std::endl;

	FragTrap	copyFrag(frag);

	copyFrag.attack("copy_target");
	copyFrag.highFivesGuys();

	std::cout << std::endl;

	return (0);
}