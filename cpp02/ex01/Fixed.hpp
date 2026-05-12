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

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
};


std::ostream& operator<<(std::ostream& os, const Fixed &fixed);

