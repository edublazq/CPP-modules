#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
AForm("ASCII form", 145, 137)
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& form):
AForm(form)
{}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& form)
{
	AForm::operator=(form);
	return (*this);
}

void	ShrubberyCreationForm::execute(const Bureaucrat &bureaucrat) const
{
	string		outname(getName() + "shrubbery");
	ofstream	output(outname.c_str());

	if (!getIsSigned())
		throw AForm::notSignedException();
	if (static_cast<unsigned int>(bureaucrat.getGrade()) > getGradeToExecute())
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
