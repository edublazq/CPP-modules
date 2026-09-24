#pragma once

#include <list>

class Span
{
private:
	unsigned int N;
	std::list<int>	myList;
public:
	Span();
	Span(const unsigned int N);
	Span(const Span& copy);
	Span& operator=(const Span& copy);
	~Span();

	void	shortestSpan();
	void	largestSpan();
};
