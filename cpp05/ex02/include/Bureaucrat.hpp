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
	Bureaucrat(string name, int n);
	Bureaucrat& operator=(const Bureaucrat &toCopy);
	~Bureaucrat();

	void			addGrade(unsigned int n);
	void			subtractGrade(unsigned int n);
	const string	getName() const;
	int				getGrade() const;

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
