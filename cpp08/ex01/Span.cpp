#include "Span.hpp"

Span::Span() : N(10)
{}

Span::Span(const uint32_t n) : N(n)
{}

Span::Span(const Span& copy)
{
	this->N = copy.N;
	this->myList = copy.myList;
}

Span& Span::operator=(const Span& copy)
{
	this->N = copy.N;
	this->myList = copy.myList;
	return (*this);
}

Span::~Span()
{
	myList.clear();
}

void	Span::addNumber(const int newNum)
{
	if (this->N > myList.size())
		myList.insert(newNum);
	else
		throw std::runtime_error("Exceeding limit of Span storage!");
}

void	Span::addRange(const int newRange[], uint32_t len)
{
	if (N < len + myList.size())
		throw std::runtime_error("Exceeding limit of Span storage!");
	for (uint32_t i = 0; i < len; i++)
		myList.insert(newRange[i]);
}

int	Span::shortestSpan()
{
	int	shortest = INT_MAX;

	if (myList.size() < 2)
		return (0);
	std::multiset<int>::iterator prev = myList.begin();
	std::multiset<int>::iterator it = prev;
	++it;
	for (; it != myList.end(); ++it, ++prev)
	{
		if (*it - *prev < shortest)
			shortest = *it - *prev;
	}
	return (shortest);
}

int	Span::largestSpan()
{
	if (myList.size() < 2)
		return (0);
	return (*myList.rbegin() - *myList.begin());
}
