#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : 
AForm(), name("ASCII form"), isSigned(false)
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& form):
name(form.name)
{}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& form)
{
	(void) form;
	return (*this);
}

void	ShrubberyCreationForm::execute(const Bureaucrat &bureaucrat)
{
	string		outname(name + "shrubbery");
	ofstream	output(outname.c_str());

	if (!isSigned)
		throw AForm::notSignedException();
	if (gradeToExecute > bureaucrat.getGrade())
		throw AForm::GradeTooLowException();
	if (!output.is_open())
		throw std::runtime_error("Outfile could not be created");
	output << "       _-_ "<< endl;
	output << "	/~~   ~~\\ " << endl;
	output << "/~~         ~~\\" << endl;
	output << "{               }" << endl;
	output << " \\  _-     -_  /" << endl;
	output << "  ~   \\\\ //  ~" << endl;
	output << "_- -   | | _- _" << endl;
	output << " _ -   | |   -_ "<< endl;
	output << "      // \\\\" << endl;
	output.close();
}
