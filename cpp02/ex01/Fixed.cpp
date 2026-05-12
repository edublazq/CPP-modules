#include "Fixed.hpp"

Fixed::Fixed(): _rawBits(0)
{
	cout << "Default constructor called" << endl;
}

Fixed::Fixed(Fixed &toCopy)
{
	cout << "Copy constructor called" << endl;
	_rawBits = toCopy.getRawBits();
}

Fixed::~Fixed()
{
	cout << "Destructor called!" << endl;
}

Fixed& Fixed::operator=(const Fixed &fixed)
{
	if (this != &fixed)
		_rawBits  = fixed.getRawBits();
	return (*this);
}

int	Fixed::getRawBits() const
{
	cout << "getRawBits called" << endl;
	return (_rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	cout << "setRawBits called" << endl;
	_rawBits = raw;
}
