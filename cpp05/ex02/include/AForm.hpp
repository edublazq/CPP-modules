#pragma once

# include "Bureaucrat.hpp"

using std::string;
using std::cout;
using std::endl;

class AForm
{
private:
	const string			name;
	const unsigned int		gradeToExecute;
	const unsigned int		gradeToSign;
	bool					isSigned;
public:
	AForm(const string& name, unsigned int gradeToSign, unsigned int gradeToExecute);
	AForm(const AForm& form);
	AForm& operator=(const AForm& form);
	virtual ~AForm() = 0;

	const string	getName() const;
	unsigned int	getGradeToExecute() const;
	unsigned int	getGradeToSign() const;
	bool			getIsSigned() const;

	void			signForm(Bureaucrat &bureaucrat);
	virtual void	execute(const Bureaucrat &bureaucrat) = 0;


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
	class notSignedException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Form is not signed");
			}
	};
};

std::ostream& operator<<(std::ostream& os, const AForm& form);
