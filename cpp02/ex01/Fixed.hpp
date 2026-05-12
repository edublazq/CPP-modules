#pragma once

#include <iostream>

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
	Fixed(Fixed &toCopy);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

