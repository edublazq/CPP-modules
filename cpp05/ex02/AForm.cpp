#include "AForm.hpp"

AForm::~AForm()
{}

const string	AForm::getName() const {return (name);}
unsigned int	AForm::getGradeToExecute() const {return (gradeToExecute);}
unsigned int	AForm::getGradeToSign() const {return (gradeToSign);}
bool			AForm::getIsSigned() const {return (isSigned);}

bool	AForm::signForm(Bureaucrat &bureaucrat)
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
