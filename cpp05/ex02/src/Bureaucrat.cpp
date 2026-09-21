#include "Bureaucrat.hpp"
#include "AForm.hpp"

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
		throw GradeTooHighException();
	if (grade < 1)
		throw GradeTooLowException();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &toCopy)
{
	(void) toCopy;
	return (*this);
}

const string	Bureaucrat::getName() const{return (name);}
int	Bureaucrat::getGrade() const{return (grade);}

void	Bureaucrat::addGrade(unsigned int n)
{
	grade += (int)n;
	if (grade > 150)
		throw GradeTooHighException();
}

void	Bureaucrat::subtractGrade(unsigned int n)
{
	grade -= (int)n;
	if (grade < 1)
		throw GradeTooLowException();
}

void	Bureaucrat::executeForm(const AForm& form) const
{
	form.execute(*this);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureau)
{
	os << bureau.getName() << ", bureaucrat grade " << bureau.getGrade();
	return (os);
}
