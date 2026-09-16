#pragma once

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <fstream>

using std::ofstream;

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& copy);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy);
		~ShrubberyCreationForm();
		void	execute(const Bureaucrat &bureaucrat);
};
