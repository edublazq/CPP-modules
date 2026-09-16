#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : 
AForm(), name("ASCII form")
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& form):
name(form.name)
{}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& form)
{
	(void) form;
	return (*this);
}

void	RobotomyRequestForm::execute(const Bureaucrat &bureaucrat)
{
	
}
