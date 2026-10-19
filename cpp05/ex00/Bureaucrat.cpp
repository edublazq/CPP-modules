#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
: name("Manolo"), grade(50)
{}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat::Bureaucrat(const Bureaucrat &toCopy)
: name(toCopy.name), grade(toCopy.grade)
{}

Bureaucrat::Bureaucrat(string name, int n)
:name(name), grade(n)
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &toCopy)
{
	if (this != &toCopy)
		grade = toCopy.grade;
	return (*this);
}

const string	Bureaucrat::getName() const{return (name);}
int	Bureaucrat::getGrade() const{return (grade);}

void	Bureaucrat::addGrade(unsigned int n)
{
	if (n > 150 || grade + static_cast<int>(n) > 150)
		throw GradeTooLowException();
	grade += static_cast<int>(n);
}

void	Bureaucrat::subtractGrade(unsigned int n)
{
	if (n > 150 || grade - static_cast<int>(n) < 1)
		throw GradeTooHighException();
	grade -= static_cast<int>(n);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureau)
{
	os << bureau.getName() << ", bureaucrat grade " << bureau.getGrade();
	return (os);
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}
