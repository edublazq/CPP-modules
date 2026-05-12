#include "Point.hpp"

Fixed sign(Point const a, Point const b, Point const c)
{
	return (
		(a.getX() - c.getX()) * (b.getY() - c.getY())
		-
		(b.getX() - c.getX()) * (a.getY() - c.getY())
	);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed f1 , f2, f3;
	bool s1, s2, s3;

	f1 = sign(point, a, b);
	f2 = sign(point, b, c);
	f3 = sign(point, c, a);
	s1 = f1 < 0;
	s2 = f2 < 0;
	s3 = f3 < 0;
	if (f1 == 0 || f2 == 0 || f3 == 0)
		return (false);
	if (s1 && s2 && s3)
		return (true);
	if (!s1 && !s2 && !s3)
		return (true);
	return (false);
}
