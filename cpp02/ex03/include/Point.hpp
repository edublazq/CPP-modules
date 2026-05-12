#pragma once

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed	_x;
		const Fixed	_y;
	public:
		Point();
		~Point();
		Point(const float x, const float y);
		Point& operator=(const Point &point);
		Point(const Point &toCopy);

		Fixed	getX() const;
		Fixed	getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

