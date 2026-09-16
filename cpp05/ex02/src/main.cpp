#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static void	testBureaucrat(void)
{
	std::cout << "\n=== Bureaucrat ===" << std::endl;

	try
	{
		Bureaucrat tooHigh("Jesus", 160);
		(void)tooHigh;
	}
	catch (const std::exception& e)
	{
		std::cout << "grade 160 -> " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat tooLow("Jesus", -2);
		(void)tooLow;
	}
	catch (const std::exception& e)
	{
		std::cout << "grade -2 -> " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat valid("Jesus", 8);
		std::cout << valid << std::endl;

		valid.addGrade(3);
		std::cout << "after addGrade(3): " << valid << std::endl;

		valid.subtractGrade(2);
		std::cout << "after subtractGrade(2): " << valid << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "unexpected exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat edge("Edge", 1);
		edge.subtractGrade(1);
		std::cout << "after subtractGrade(1) on grade 1: " << edge << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "subtractGrade underflow -> " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat top("Top", 150);
		top.addGrade(1);
		std::cout << "after addGrade(1) on grade 150: " << top << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "addGrade overflow -> " << e.what() << std::endl;
	}

	Bureaucrat original("Original", 42);
	Bureaucrat copy(original);
	std::cout << "copy constructed: " << copy << std::endl;

	Bureaucrat assigned("ToOverwrite", 10);
	assigned = original;
	std::cout << "copy assigned: " << assigned << std::endl;
}

template <typename FormType>
static void	testFormLifecycle(const std::string& formLabel,
	Bureaucrat& weakSigner, Bureaucrat& strongSigner, Bureaucrat& weakExecutor,
	Bureaucrat& strongExecutor)
{
	std::cout << "\n=== " << formLabel << " ===" << std::endl;

	FormType unsignedForm;
	std::cout << unsignedForm << std::endl;

	try
	{
		unsignedForm.execute(strongExecutor);
	}
	catch (const std::exception& e)
	{
		std::cout << "execute before signing -> " << e.what() << std::endl;
	}

	try
	{
		unsignedForm.signForm(weakSigner);
	}
	catch (const std::exception& e)
	{
		std::cout << weakSigner.getName() << " failed to sign -> " << e.what() << std::endl;
	}

	FormType signableForm;
	signableForm.signForm(strongSigner);
	std::cout << signableForm << std::endl;

	try
	{
		signableForm.execute(weakExecutor);
	}
	catch (const std::exception& e)
	{
		std::cout << weakExecutor.getName() << " failed to execute -> " << e.what() << std::endl;
	}

	try
	{
		signableForm.execute(strongExecutor);
		std::cout << strongExecutor.getName() << " executed " << formLabel << " successfully" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "unexpected execute failure -> " << e.what() << std::endl;
	}
}

int	main(void)
{
	testBureaucrat();

	Bureaucrat lowGrade("Intern", 150);
	Bureaucrat midGrade("Manager", 100);
	Bureaucrat highGrade("Director", 1);

	testFormLifecycle<ShrubberyCreationForm>("ShrubberyCreationForm",
		lowGrade, highGrade, lowGrade, highGrade);
	testFormLifecycle<RobotomyRequestForm>("RobotomyRequestForm",
		lowGrade, highGrade, lowGrade, highGrade);
	testFormLifecycle<PresidentialPardonForm>("PresidentialPardonForm",
		lowGrade, highGrade, lowGrade, highGrade);

	return (0);
}
