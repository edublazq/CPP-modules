#include "Bureaucrat.hpp"

static void	testConstructor(const std::string& name, int grade)
{
	try
	{
		Bureaucrat	b(name, grade);
		std::cout << "constructed -> " << b << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "grade " << grade << " -> Exception: " << e.what() << std::endl;
	}
}

static void	testAdd(Bureaucrat& b, unsigned int n)
{
	try
	{
		b.addGrade(n);
		std::cout << "addGrade(" << n << ") -> " << b << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "addGrade(" << n << ") -> Exception: " << e.what() << " (" << b << ")" << std::endl;
	}
}

static void	testSubtract(Bureaucrat& b, unsigned int n)
{
	try
	{
		b.subtractGrade(n);
		std::cout << "subtractGrade(" << n << ") -> " << b << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "subtractGrade(" << n << ") -> Exception: " << e.what() << " (" << b << ")" << std::endl;
	}
}

int	main(void)
{
	std::cout << "=== constructor ===" << std::endl;
	testConstructor("TooLow", 151);
	testConstructor("TooLow", 160);
	testConstructor("TooHigh", 0);
	testConstructor("TooHigh", -2);
	testConstructor("Highest", 1);
	testConstructor("Lowest", 150);
	testConstructor("Jesus", 8);

	std::cout << "\n=== add / subtract ===" << std::endl;
	Bureaucrat	b("Jesus", 8);
	testAdd(b, 3);
	testSubtract(b, 2);
	testSubtract(b, 8);
	testSubtract(b, 1000000);
	testAdd(b, 1000000);
	testAdd(b, 150);
	testAdd(b, 142);
	testAdd(b, 1);
	testSubtract(b, 149);

	std::cout << "\n=== copy / assignation ===" << std::endl;
	Bureaucrat	original("Original", 42);
	Bureaucrat	copy(original);
	Bureaucrat	assigned("ToOverwrite", 10);
	assigned = original;
	std::cout << "copy: " << copy << std::endl;
	std::cout << "assigned: " << assigned << std::endl;
	return (0);
}
