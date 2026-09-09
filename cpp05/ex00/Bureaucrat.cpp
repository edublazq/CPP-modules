#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
: name("Manolo"), grade(50)
{}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat::Bureaucrat(const Bureaucrat &toCopy)
: name(toCopy.name), grade(toCopy.grade)
{}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &toCopy)
{
	return (*this);
}

const string	Bureaucrat::getName() const{return (name);}
const int	Bureaucrat::getGrade() const{return (grade);}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureau)
{
	os << bureau.getName() << ", bureaucrat grade " << bureau.getGrade();
	return (os);
}
