#include "Phonebook.hpp"

static std::string	strNotEmpty(const std::string cout_msg)
{
	std::string	input;

	do{
		std::cout << GREEN << cout_msg << RESET;
		std::getline(std::cin, input);
		if (input.empty())
			std::cerr << RED << "Introduce a valid value!" << RESET << std::endl;
	} while (input.empty());
	return (input);
}

static	std::string	num_input(void)
{
	std::string	input;
	int			num;
	bool		valid;

	do{
		input = strNotEmpty("Enter phone number: ");
		std::stringstream	ss(input);
		if (ss >> num && ss.eof())
			valid = true;
		else
			valid = false;
		if (num < 100000000 || num > 999999999)
			valid = false;
		if (valid == false)
			std::cerr << RED << "Please introduce a valid number!" << RESET << std::endl;
	} while (valid == false);
	return (input);
}

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

void	PhoneBook::setContact(Contact &newContact)
{
	_contacts[_n_contacts % 8] = newContact;
	_n_contacts++;
}

void	PhoneBook::add(void)
{
	Contact		contact;

	contact.set_firstName(strNotEmpty("First name: "));
	contact.set_lastName(strNotEmpty("Last name: "));
	contact.set_nickName(strNotEmpty("Nickname: "));
	contact.set_darkSecret(strNotEmpty("Darkest secret: "));
	contact.set_num(num_input());
	this->setContact(contact);
}
