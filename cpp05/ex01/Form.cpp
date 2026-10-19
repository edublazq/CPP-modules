#include "Form.hpp"

Form::Form()
: name("Manolo"), gradeToExecute(75), gradeToSign(50), isSigned(false)
{}

Form::~Form()
{}

Form::Form(const Form &toCopy)
: name(toCopy.name), gradeToExecute(toCopy.gradeToExecute), gradeToSign(toCopy.gradeToSign), isSigned(toCopy.isSigned)
{}

Form::Form(string name, unsigned int execute, bool isSigned, unsigned int sign)
:name(name), gradeToExecute(execute), gradeToSign(sign), isSigned(isSigned)
{
	if (gradeToExecute < 1 || gradeToSign < 1)
		throw GradeTooHighException();
	if (gradeToExecute > 150 || gradeToSign > 150)
		throw GradeTooLowException();
}

Form& Form::operator=(const Form &toCopy)
{
	isSigned = toCopy.isSigned;
	return (*this);
}

const string	Form::getName() const {return (name);}
unsigned int	Form::getGradeToExecute() const {return (gradeToExecute);}
unsigned int	Form::getGradeToSign() const {return (gradeToSign);}
bool			Form::getIsSigned() const {return (isSigned);}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (static_cast<unsigned int>(bureaucrat.getGrade()) > gradeToSign)
		throw GradeTooLowException();
	isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << form.getName() << " form was ";
	if (form.getIsSigned() == false)
		os << "not ";
	os << "signed and to sign it is necessary " << form.getGradeToSign();
	os << std::endl;
	os << "To execute it you need " << form.getGradeToExecute() << " grade";
	return (os);
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}
