#pragma once
#include "Contact.hpp"
#include <sstream>

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"

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
		~PhoneBook(void);
};
