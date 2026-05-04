#include "Phonebook.hpp"

int main()
{
	PhoneBook	phoneBook;

	phoneBook.add();
	Contact	contact = phoneBook.getContact(0);
	contact.display();
	return (0);
}
