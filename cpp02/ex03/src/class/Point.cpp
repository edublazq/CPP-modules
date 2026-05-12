#include "Point.hpp"

Point::Point(): _x(0), _y(0)
{
}

Point::~Point()
{
}

Point::Point(const Point &toCopy)
	: _x(toCopy.getX()), _y(toCopy.getY())
{
}

Point::Point(const float x, const float y)
	:_x(x), _y(y)
{
}

Point&	Point::operator=(const Point &point)
{
	(void)point;
	return (*this);
}

Fixed	Point::getX() const
{
	return (_x);
}

Fixed	Point::getY() const
{
	return (_y);
}
