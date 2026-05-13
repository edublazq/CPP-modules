#include "ScavTrap.hpp"

int	main(void)
{
	cout << "===== CLAPTRAP TEST =====" << endl;

		ClapTrap	clap("Pepe");

		clap.attack("enemy");
		clap.takeDamage(5);
		clap.beRepaired(3);

		cout << endl;

		cout << "===== SCAVTRAP TEST =====" << endl;

		ScavTrap	scav("Guardian");

		scav.attack("intruder");
		scav.takeDamage(30);
		scav.beRepaired(10);
		scav.guardGate();

		cout << endl;

		cout << "===== COPY CONSTRUCTOR TEST =====" << endl;

		ScavTrap	copy(scav);

		copy.attack("copy_target");

		cout << endl;

		cout << "===== ASSIGNATION TEST =====" << endl;

		ScavTrap	assign;

		assign = scav;

		assign.attack("assigned_target");

		cout << endl;
}