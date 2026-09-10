#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat("Jesus", 160);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}
	try
	{
		Bureaucrat("Jesus", -2);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}
	try
	{
		Bureaucrat("Jesus", 8);
		std::cout << "jesus furula!, no exception" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
