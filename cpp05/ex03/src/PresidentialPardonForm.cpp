#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
AForm("Presidential Form", 25, 5)
{}

PresidentialPardonForm::PresidentialPardonForm(const string& name) :
AForm(name, 25, 5)
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& form):
AForm(form)
{}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& form)
{
	AForm::operator=(form);
	return (*this);
}

void	PresidentialPardonForm::execute(const Bureaucrat &bureaucrat) const
{
	if (!getIsSigned())
		throw AForm::notSignedException();
	if (static_cast<unsigned int>(bureaucrat.getGrade()) > getGradeToExecute())
		throw AForm::GradeTooLowException();
	cout << getName() << " has been pardoned by Zaphod Beeblebrox." << endl;
}
