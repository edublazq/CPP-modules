#pragma once

# include <stdexcept>
# include <exception>
# include <iostream>
# include <string>

using std::string;

class Bureaucrat
{
private:
	const string	name;
	int				grade;
public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat &toCopy);
	Bureaucrat& operator=(const Bureaucrat &toCopy);
	~Bureaucrat();

	const string	getName() const;
	const int	getGrade() const;

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

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureau);
