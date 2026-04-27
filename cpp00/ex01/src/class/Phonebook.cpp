#include "class/Phonebook.hpp"

PhoneBook::PhoneBook()
{
	_n_contacts = 0;
	std::cout << "Phonebook constructor called" << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "PhoneBook destructor called" << std::endl;
}

Contact	PhoneBook::getContact(int num)
{
	return (_contacts[num % 8]);
}

void	PhoneBook::setContact(Contact newContact)
{
	_contacts[_n_contacts % 8] = newContact;
	_n_contacts++;
}

void	PhoneBook::add(void)
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	darkSecret;
	int			num;

	std::cout << "Name: ";
	std::cin >> firstName;

	std::cout << "Last name: ";
	std::cin >> lastName;

	std::cout << "Nickname: ";
	std::cin >> nickName;

	std::cout << "Darkest secret: ";
	std::cin >> darkSecret;

	std::cin >> 
}
