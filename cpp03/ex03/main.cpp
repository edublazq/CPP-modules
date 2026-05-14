#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "========== DIAMONDTRAP CREATION =========="
			  << std::endl;

	DiamondTrap	diamond("DiamondBoy");

	std::cout << std::endl;

	std::cout << "========== WHO AM I =========="
			  << std::endl;

	diamond.whoAmI();

	std::cout << std::endl;

	std::cout << "========== ATTACK TEST =========="
			  << std::endl;

	diamond.attack("enemy");

	std::cout << std::endl;

	std::cout << "========== DAMAGE / REPAIR TEST =========="
			  << std::endl;

	diamond.takeDamage(30);
	diamond.beRepaired(15);

	std::cout << std::endl;

	std::cout << "========== SPECIAL ABILITIES =========="
			  << std::endl;

	diamond.guardGate();
	diamond.highFivesGuys();

	std::cout << std::endl;

	std::cout << "========== COPY CONSTRUCTOR =========="
			  << std::endl;

	DiamondTrap copy(diamond);

	copy.whoAmI();
	copy.attack("copy_target");

	std::cout << std::endl;

	std::cout << "========== ASSIGNATION =========="
			  << std::endl;

	DiamondTrap assigned;

	assigned = diamond;

	assigned.whoAmI();
	assigned.attack("assigned_target");

	std::cout << std::endl;

	std::cout << "========== ENERGY DRAIN =========="
			  << std::endl;

	for (int i = 0; i < 55; i++)
		diamond.attack("wall");

	std::cout << std::endl;

	std::cout << "========== DEATH TEST =========="
			  << std::endl;

	diamond.takeDamage(9999);

	diamond.attack("ghost");
	diamond.beRepaired(10);
	diamond.guardGate();
	diamond.highFivesGuys();

	std::cout << std::endl;

	std::cout << "========== POLYMORPHIC FEEL =========="
			  << std::endl;

	ClapTrap* ptr = new DiamondTrap("Ultimate");

	ptr->attack("training_dummy");

	delete ptr;

	std::cout << std::endl;

	std::cout << "========== END =========="
			  << std::endl;

	return (0);
}