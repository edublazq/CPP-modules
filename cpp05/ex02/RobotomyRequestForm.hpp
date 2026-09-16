#pragma once

# include "AForm.hpp"
# include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		const string	name;
		const int		gradeToSign = 72;
		const int		gradeToExecute = 45;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& copy);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);
		~RobotomyRequestForm();
		void	execute(const Bureaucrat &bureaucrat);
}
