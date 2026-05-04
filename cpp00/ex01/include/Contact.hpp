#pragma once
#include <string>
#include <iostream>

class	Contact
{
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_darkSecret;
		std::string	_num;
	public:
		Contact();
		Contact(std::string s1, std::string s2, std::string s3, std::string s4, int num);
		~Contact();

		std::string get_firstName(void) const { return _firstName; }
		void set_firstName(const std::string& value) { _firstName = value; }
		std::string get_lastName(void) const { return _lastName; }
		void set_lastName(const std::string& value) { _lastName = value; }
		std::string get_nickName(void) const { return _nickName; }
		void set_nickName(const std::string& value) { _nickName = value; }
		std::string get_darkSecret(void) const { return _darkSecret; }
		void set_darkSecret(const std::string& value) { _darkSecret = value; }
		std::string get_num(void) const { return _num; }
		void set_num(const std::string value) { _num = value; }

		void display();
};

