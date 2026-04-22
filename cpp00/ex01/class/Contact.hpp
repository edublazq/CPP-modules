#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class	Contact
{
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_darkSecret;
		int			_num;
	public:
		Contact();
		Contact(std::string s1, std::string s2, std::string s3, std::string s4, int num);
		~Contact();
};

#endif
