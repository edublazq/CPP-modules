#include "AForm.hpp"

AForm::AForm()
: name("Default form")
{}

AForm::~AForm()
{}

AForm::AForm(const AForm &toCopy)
: name(toCopy.name), gradeToExecute(toCopy.gradeToExecute), gradeToSign(toCopy.gradeToSign), isSigned(toCopy.isSigned)
{}

AForm& AForm::operator=(const AForm& form)
{
	(void)form;
	return (*this);
}

const string	AForm::getName() const {return (name);}
unsigned int	AForm::getGradeToExecute() const {return (gradeToExecute);}
unsigned int	AForm::getGradeToSign() const {return (gradeToSign);}
bool			AForm::getIsSigned() const {return (isSigned);}

void	AForm::signForm(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
	{
		cout << bureaucrat.getName() << " signed " << name << endl;
		isSigned = true;
		return ;
	}
	cout << bureaucrat.getName() << " couldn't sign " << name << "because ";
	throw GradeTooLowException();
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
