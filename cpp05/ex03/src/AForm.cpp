#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const string& name, unsigned int gradeToSign, unsigned int gradeToExecute)
: name(name), gradeToExecute(gradeToExecute), gradeToSign(gradeToSign), isSigned(false)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::~AForm()
{}

AForm::AForm(const AForm &toCopy)
: name(toCopy.name), gradeToExecute(toCopy.gradeToExecute), gradeToSign(toCopy.gradeToSign), isSigned(toCopy.isSigned)
{}

AForm& AForm::operator=(const AForm& form)
{
	isSigned = form.isSigned;
	return (*this);
}

const string	AForm::getName() const {return (name);}
unsigned int	AForm::getGradeToExecute() const {return (gradeToExecute);}
unsigned int	AForm::getGradeToSign() const {return (gradeToSign);}
bool			AForm::getIsSigned() const {return (isSigned);}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (static_cast<unsigned int>(bureaucrat.getGrade()) > gradeToSign)
		throw GradeTooLowException();
	isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& Form)
{
	os << Form.getName() << " Form was ";
	if (Form.getIsSigned() == false)
		os << "not ";
	os << "signed and to sign it is necessary " << Form.getGradeToSign();
	os << std::endl;
	os << "To execute it you need " << Form.getGradeToExecute() << " grade";
	return (os);
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char*	AForm::notSignedException::what() const throw()
{
	return ("Form is not signed");
}
