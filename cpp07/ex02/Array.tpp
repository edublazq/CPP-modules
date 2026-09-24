#include "Array.hpp"

template <typename T>
Array<T>::Array() : elements(NULL), n_elements(0)
{}

template <typename T>
Array<T>::Array(const unsigned int n) : elements(new T[n]), n_elements(n)
{}

template <typename T>
Array<T>& Array<T>::operator=(const Array& copy)
{
	delete[] elements;
	this->elements = copy.elements;
	this->n_elements = copy.n_elements;
	return (*this);
}

template <typename T>
Array<T>::Array(const Array& copy)
{
	this->elements = copy.elements;
	this->n_elements = copy.n_elements;
}

template <typename T>
Array<T>::~Array()
{
	if (n_elements > 0)
		delete[] elements;
}

template <typename T>
T& Array<T>::operator[](const unsigned int n)
{
	if (n > n_elements)
		throw std::exception();
	return (this->elements[n]);
}


template <typename T>
unsigned int	Array<T>::size(void) const
{
	return (this->n_elements);
}
