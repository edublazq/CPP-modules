#pragma once

#include <algorithm>
#include <set>
#include <stdint.h>
#include <limits.h>
#include <stdexcept>
#include <iostream>

class Span
{
private:
	uint32_t	N;
	std::multiset<int>	myList;
public:
	Span();
	Span(const uint32_t n);
	Span(const Span& copy);
	Span& operator=(const Span& copy);
	~Span();

	void		addNumber(const int newNum);
	void		addRange(const int newRange[], uint32_t len);
	int			shortestSpan();
	int			largestSpan();
};
