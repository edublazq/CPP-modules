#pragma once

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <fstream>

using std::ofstream;

class ShrubberyCreationForm : public AForm
{
	private:
		const string	name;
		const int		gradeToSign = 145;
		const int		gradeToExecute = 137;
		bool			isSigned;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& copy);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy);
		~ShrubberyCreationForm();
		void	execute(const Bureaucrat &bureaucrat);
}
