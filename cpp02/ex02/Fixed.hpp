#pragma once

#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

class Fixed
{
private:
	int	_rawBits;
	static const int _fractionalBits = 8;
public:
	Fixed();
	Fixed& operator=(const Fixed &fixed);
	Fixed(const Fixed &toCopy);
	Fixed(const int fromInt);
	Fixed(const float fromFloat);
	~Fixed();

	bool operator<(const Fixed &fixed) const;
	bool operator>(const Fixed &fixed) const;
	bool operator<=(const Fixed &fixed) const;
	bool operator>=(const Fixed &fixed) const;
	bool operator==(const Fixed &fixed) const;

	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);

	Fixed operator+(const Fixed &fixed) const;
	Fixed operator-(const Fixed &fixed) const;
	Fixed operator*(const Fixed &fixed) const;
	Fixed operator/(const Fixed &fixed) const;

	static Fixed& min(Fixed &f1, Fixed &f2);
	static Fixed& max(Fixed &f1, Fixed &f2);
	static const Fixed& min(const Fixed &f1, const Fixed &f2);
	static const Fixed& max(const Fixed &f1, const Fixed &f2);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
};


std::ostream& operator<<(std::ostream& os, const Fixed &fixed);

