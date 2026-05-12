#include "Fixed.hpp"

std::ostream& operator<<(std::ostream& os, const Fixed &fixed)
{
	os << fixed.toFloat();

	return (os);
}

Fixed::Fixed(): _rawBits(0)
{
	cout << "Default constructor called" << endl;
}

Fixed::Fixed(Fixed const &toCopy)
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

Fixed::Fixed(const int fromInt)
{
	_rawBits = fromInt << _fractionalBits;
}

Fixed::Fixed(const float fromFloat)
{
	int	bitsMove = 1 << _fractionalBits;
	float	newFloat = fromFloat * bitsMove;

	_rawBits = roundf(newFloat);
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

float	Fixed::toFloat(void) const
{
	int		bitsMove = 1 << _fractionalBits;

	return ((float)_rawBits / bitsMove);
}

int	Fixed::toInt(void) const
{
	return (_rawBits/(1 << _fractionalBits));
}
