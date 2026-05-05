#pragma once
#include "Contact.hpp"
#include <sstream>
#include <iomanip>

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"

std::string	strNotEmpty(const std::string cout_msg);
std::string formatColumn(const std::string& str);

class PhoneBook
{
	private:
		Contact	_contacts[8];
		int		_n_contacts;
	public:
		PhoneBook(void);
		Contact getContact(int num);
		void	setContact(Contact &newContact);

		void	add(void);
		void	search(void);
		~PhoneBook(void);
};
