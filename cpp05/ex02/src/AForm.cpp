#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const string& name, unsigned int gradeToSign, unsigned int gradeToExecute)
: name(name), gradeToExecute(gradeToExecute), gradeToSign(gradeToSign), isSigned(false)
{
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooHighException();
	if (gradeToSign < 1 || gradeToExecute < 1)
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

void	AForm::signForm(Bureaucrat &bureaucrat)
{
	if (static_cast<unsigned int>(bureaucrat.getGrade()) > gradeToSign)
	{
		cout << bureaucrat.getName() << " couldn't sign " << name << "because ";
		throw GradeTooLowException();
	}
	cout << bureaucrat.getName() << " signed " << name << endl;
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
