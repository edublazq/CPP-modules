#include "Bureaucrat.hpp"
#include "Form.hpp"

static void	testFormConstructor(unsigned int execute, unsigned int sign)
{
	try
	{
		Form	f("Tax", execute, false, sign);
		std::cout << "constructed -> " << f << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "exec " << execute << " / sign " << sign << " -> Exception: " << e.what() << std::endl;
	}
}

int	main(void)
{
	std::cout << "=== Bureaucrat ===" << std::endl;
	try { Bureaucrat("Jesus", 160); }
	catch (const std::exception& e) { std::cout << "160 -> " << e.what() << std::endl; }
	try { Bureaucrat("Jesus", 0); }
	catch (const std::exception& e) { std::cout << "0 -> " << e.what() << std::endl; }

	std::cout << "\n=== Form constructor ===" << std::endl;
	testFormConstructor(10, 20);
	testFormConstructor(0, 20);
	testFormConstructor(10, 0);
	testFormConstructor(151, 20);
	testFormConstructor(10, 151);
	testFormConstructor(1, 150);

	std::cout << "\n=== beSigned ===" << std::endl;
	Bureaucrat	boss("Boss", 5);
	Bureaucrat	exact("Exact", 20);
	Bureaucrat	clerk("Clerk", 100);
	Form		form("Tax", 10, false, 20);

	try
	{
		form.beSigned(clerk);
	}
	catch (const std::exception& e)
	{
		std::cout << "beSigned(clerk) -> Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Bureaucrat::signForm ===" << std::endl;
	std::cout << form << std::endl;
	clerk.signForm(form);
	std::cout << form << std::endl;
	exact.signForm(form);
	std::cout << form << std::endl;

	Form	form2("Other", 10, false, 20);
	boss.signForm(form2);
	std::cout << form2 << std::endl;
	boss.signForm(form2);

	std::cout << "\n=== copy / assignation ===" << std::endl;
	Form	copy(form);
	Form	assigned("ToOverwrite", 1, false, 1);
	assigned = form;
	std::cout << "copy: " << copy << std::endl;
	std::cout << "assigned: " << assigned << std::endl;
	return (0);
}
