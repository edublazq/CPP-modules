#include "Form.hpp"

Form::Form()
: name("Manolo"), gradeToSign(50), isSigned(false),gradeToExecute(75) 
{}

Form::~Form()
{}

Form::Form(const Form &toCopy)
: name(toCopy.name), gradeToExecute(toCopy.gradeToExecute), gradeToSign(toCopy.gradeToSign), isSigned(toCopy.isSigned)
{}

Form::Form(string name, unsigned int execute, bool isSigned, unsigned int sign)
:name(name), gradeToExecute(execute), isSigned(isSigned), gradeToSign(sign)
{
	if (gradeToExecute > 150 || gradeToSign > 150)
		throw GradeTooHighException();
	if (gradeToExecute < 1 || gradeToSign < 1)
		throw GradeTooLowException();
}

Form& Form::operator=(const Form &toCopy)
{
	(void) toCopy;
	isSigned = toCopy.isSigned;
	return (*this);
}

const string	Form::getName() const {return (name);}
unsigned int	Form::getGradeToExecute() const {return (gradeToExecute);}
unsigned int	Form::getGradeToSign() const {return (gradeToSign);}
bool			Form::getIsSigned() const {return (isSigned);}

bool	Form::signForm(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
	{
		cout << bureaucrat.getName() << " signed " << name << endl;
		isSigned = true;
		return (true);
	}
	cout << bureaucrat.getName() << " couldn't sign " << name << " because grade isn't enough!" << endl;
	return (false);
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
