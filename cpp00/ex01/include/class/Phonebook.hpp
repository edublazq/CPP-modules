#pragma once
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	_contacts[8];
		int		_n_contacts;
	public:
		PhoneBook(void);
		Contact getContact(int num);
		void	setContact(Contact newContact);

		void	add(void);
		~PhoneBook(void);
};
