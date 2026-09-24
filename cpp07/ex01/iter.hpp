#pragma once

template <typename A, typename B, typename C>
void	iter(A *a, const B &b, C &c)
{
	B	i = 0;

	while (i < b)
	{
		c(a)
		i++;
	}
}
