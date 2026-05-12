#include "Fixed.hpp"

std::ostream& operator<<(std::ostream& os, const Fixed &fixed)
{
	os << fixed.toFloat();

	return (os);
}

Fixed::Fixed(): _rawBits(0)
{
}

Fixed::Fixed(Fixed const &toCopy)
{
	_rawBits = toCopy.getRawBits();
}

Fixed::~Fixed()
{
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

Fixed& Fixed::operator=(const Fixed &fixed)
{
	if (this != &fixed)
		_rawBits  = fixed.getRawBits();
	return (*this);
}

bool Fixed::operator<(const Fixed &fixed) const
{
	return (_rawBits < fixed.getRawBits());
}

bool Fixed::operator>(const Fixed &fixed) const
{
	return (_rawBits > fixed.getRawBits());
}

bool Fixed::operator>=(const Fixed &fixed) const
{
	return (_rawBits >= fixed.getRawBits());
}

bool Fixed::operator<=(const Fixed &fixed) const
{
	return (_rawBits <= fixed.getRawBits());
}

bool Fixed::operator==(const Fixed &fixed) const
{
	return (_rawBits == fixed.getRawBits());
}

Fixed& Fixed::operator++()
{
	_rawBits++;

	return (*this);
}

Fixed& Fixed::operator--()
{
	_rawBits--;

	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);

	_rawBits++;
	return (temp);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);

	_rawBits--;
	return (temp);
}

Fixed Fixed::operator+(const Fixed &fixed) const
{
	Fixed	result;

	result.setRawBits(_rawBits + fixed.getRawBits());
	return (result);
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
	Fixed	result;

	result.setRawBits(_rawBits - fixed.getRawBits());
	return (result);
}

/* OPERADORES MULT Y DIV MAL HECHOS, REPASAR */

Fixed Fixed::operator*(const Fixed &fixed) const
{
	Fixed	result;

	result = this->toFloat() * fixed.toFloat();
	return (result);
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
	Fixed result;

	result = this->toFloat() / fixed.toFloat();
	return (result);
}

int	Fixed::getRawBits() const
{
	return (_rawBits);
}

void	Fixed::setRawBits(int const raw)
{
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

Fixed& Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1 < f2)
		return (f1);
	return (f2);
}

Fixed& Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1 < f2)
		return (f2);
	return (f1);
}

const Fixed& Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if (f1 < f2)
		return (f1);
	return (f2);
}

const Fixed& Fixed::max(const Fixed &f1, const Fixed &f2)
{
	if (f1 < f2)
		return (f2);
	return (f1);
}
