#include "Intern.hpp"

Intern::Intern()
{}

Intern::Intern(const Intern &toCopy)
{
	(void) toCopy;
}

Intern&	Intern::operator=(const Intern &toCopy)
{
	(void) toCopy;
	return (*this);
}

Intern::~Intern()
{}

AForm*	Intern::createShruberry(const string &name) {return (new ShrubberyCreationForm(name));}
AForm*	Intern::createRobotomy(const string &name) {return (new RobotomyRequestForm(name));}
AForm*	Intern::createPardon(const string &name) {return (new PresidentialPardonForm(name));}

const char*	Intern::UnknownFormException::what() const throw()
{
	return ("Unknown form type");
}

AForm*	Intern::makeForm(const string &name, const string &target) const
{
	static const string names[3] = 
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	static AForm* (*creators[3])(const string &) =
	{
		createShruberry,
		createRobotomy,
		createPardon
	};

	for (int i = 0; i < 3; i++)
	{
		if (name == names[i])
		{
			cout << "Intern creates " << name << endl;
			return (creators[i](target));
		}
	}
	throw UnknownFormException();
}
