#pragma once

# include "Bureaucrat.hpp"

using std::string;
using std::cout;
using std::endl;

class Form
{
private:
	const string			name;
	const unsigned int		gradeToExecute;
	const unsigned int		gradeToSign;
	bool					isSigned;
public:
	Form();
	Form(const Form &toCopy);
	Form(string name, unsigned int execute, bool isSigned, unsigned int sign);
	Form& operator=(const Form &toCopy);
	~Form();

	const string	getName() const;
	unsigned int	getGradeToExecute() const;
	unsigned int	getGradeToSign() const;
	bool			getIsSigned() const;

	bool	signForm(Bureaucrat &bureaucrat);

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Grade is too high");
			}
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Grade is too low");
			}
	};

};

std::ostream& operator<<(std::ostream& os, const Form& form);
