#include "Contact.hpp"

Contact::Contact(void)
{
	_firstName = "Manolo";
	_lastName = "Lama";
	_nickName = "Pedratxe";
	_darkSecret = "Tocar la armonica";
	_num = "615329574";
}

Contact::Contact(std::string s1, std::string s2, std::string s3, std::string s4, int num)
{
	_firstName = s1;
	_lastName = s2;
	_nickName = s3;
	_darkSecret = s4;
	_num = num;
}

void	Contact::display()
{
	std::cout << "NAME: " << get_firstName() << std::endl;
	std::cout << "LAST NAME: " << get_lastName() << std::endl;
	std::cout << "NICKNAME: " << get_nickName() << std::endl;
	std::cout << "DARKEST SECRET: " << get_darkSecret() << std::endl;
	std::cout << "NUMBER: " << get_num() << std::endl;
}

Contact::~Contact()
{
}

