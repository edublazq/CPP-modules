#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	_contacts[8];
	public:
		PhoneBook();
		Contact getContact(int num);
		void	setContact(Contact newContact);
		~PhoneBook();
};

#endif
