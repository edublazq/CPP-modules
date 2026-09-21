#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() :
AForm("ASCII form", 72, 45)
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& form):
AForm(form)
{}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& form)
{
	AForm::operator=(form);
	return (*this);
}

void	RobotomyRequestForm::execute(const Bureaucrat &bureaucrat) const
{
	if (!getIsSigned())
		throw AForm::notSignedException();
	if (static_cast<unsigned int>(bureaucrat.getGrade()) > getGradeToExecute())
		throw AForm::GradeTooLowException();
	cout << "* drilling noises *" << endl;
	static bool	seeded = false;
	if (!seeded)
	{
		srand(static_cast<unsigned int>(time(NULL)));
		seeded = true;
	}
	if (rand() % 2 == 0)
		cout << getName() << " has been robotomized successfully" << endl;
	else
		cout << "The robotomy of " << getName() << " failed" << endl;
}
