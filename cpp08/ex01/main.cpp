#include "Span.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "-- basic usage --" << std::endl;
	Span	sp(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "largest: " << sp.largestSpan() << std::endl;

	std::cout << "-- default constructor (N=10) --" << std::endl;
	Span	def;
	for (int i = 0; i < 10; i++)
		def.addNumber(i * i);
	std::cout << "shortest: " << def.shortestSpan() << std::endl;
	std::cout << "largest: " << def.largestSpan() << std::endl;

	std::cout << "-- copy constructor --" << std::endl;
	Span	copySp(sp);
	try
	{
		copySp.addNumber(100);
	}
	catch (const std::exception& e)
	{
		std::cout << "caught: " << e.what() << std::endl;
	}
	std::cout << "original shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "copy shortest: " << copySp.shortestSpan() << std::endl;
	std::cout << "original largest: " << sp.largestSpan() << std::endl;
	std::cout << "copy largest: " << copySp.largestSpan() << std::endl;

	std::cout << "-- operator= --" << std::endl;
	Span	assigned(20);
	assigned = sp;
	std::cout << "assigned shortest: " << assigned.shortestSpan() << std::endl;
	std::cout << "assigned largest: " << assigned.largestSpan() << std::endl;

	std::cout << "-- negative numbers --" << std::endl;
	Span	negSp(5);
	negSp.addNumber(-10);
	negSp.addNumber(5);
	negSp.addNumber(-3);
	negSp.addNumber(20);
	std::cout << "shortest: " << negSp.shortestSpan() << std::endl;
	std::cout << "largest: " << negSp.largestSpan() << std::endl;

	std::cout << "-- single element --" << std::endl;
	Span	one(5);
	one.addNumber(42);
	std::cout << "shortest: " << one.shortestSpan() << std::endl;
	std::cout << "largest: " << one.largestSpan() << std::endl;

	std::cout << "-- empty span --" << std::endl;
	Span	empty(5);
	std::cout << "shortest: " << empty.shortestSpan() << std::endl;
	std::cout << "largest: " << empty.largestSpan() << std::endl;

	std::cout << "-- exceeding N --" << std::endl;
	Span	small(2);
	small.addNumber(1);
	small.addNumber(2);
	try
	{
		small.addNumber(3);
	}
	catch (const std::exception& e)
	{
		std::cout << "caught: " << e.what() << std::endl;
	}
	std::cout << "shortest: " << small.shortestSpan() << std::endl;
	std::cout << "largest: " << small.largestSpan() << std::endl;

	return (0);
}
