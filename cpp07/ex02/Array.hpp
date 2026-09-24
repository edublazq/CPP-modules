#pragma once

#include <exception>
#include <cstddef>

template <typename T> class Array
{
private:
	T				*elements;
	unsigned int	n_elements;
public:
	Array();
	Array(const Array& copy);
	Array& operator=(const Array& copy);
	Array(const unsigned int n);

	T& operator[](const unsigned int n);
	unsigned int	size(void) const;
	~Array();
};

#include "Array.tpp"
