#include "Phonebook.hpp"

int main()
{
	PhoneBook	phonebook;
	std::string	input;

	std::cout << "\n====================================\n";
	std::cout << "        📞 PHONEBOOK MENU\n";
	std::cout << "====================================\n";
	std::cout << "  ADD    - Add a new contact\n";
	std::cout << "  SEARCH - Search contacts\n";
	std::cout << "  EXIT   - Exit program\n";
	std::cout << "------------------------------------\n";
	while (true)
	{
		input = strNotEmpty("Introduce your option: ");
		if (input == "ADD" || input == "add" || input == "Add")
			phonebook.add();
		else if (input == "SEARCH" || input == "Search" || input == "search")
			phonebook.search();
		else if (input == "EXIT" || input == "Exit" || input == "exit")
			break ;
		else
		{
			std::cout << "\n====================================\n";
			std::cout << "        📞 PHONEBOOK MENU\n";
			std::cout << "====================================\n";
			std::cout << "  ADD    - Add a new contact\n";
			std::cout << "  SEARCH - Search contacts\n";
			std::cout << "  EXIT   - Exit program\n";
			std::cout << "------------------------------------\n";
		}
	}
	return (0);
}
