#pragma once

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
private:
	static AForm* createShruberry(const string &name);
	static AForm* createRobotomy(const string &name);
	static AForm* createPardon(const string &name);
public:
	Intern();
	Intern(const Intern& toCopy);
	Intern& operator=(const Intern& toCopy);
	~Intern();

	AForm*	makeForm(const string &type, const string &target) const;

	class UnknownFormException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};
