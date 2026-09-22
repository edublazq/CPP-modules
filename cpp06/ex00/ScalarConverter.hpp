#pragma once

# include <string>
# include <iostream>
# include <limits.h>
# include <cstdlib>
# include <cstring>

using std::string;
using std::cout;
using std::endl;

typedef enum	e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO,
	INVALID
};

typedef struct s_conversion
{
	char	c;
	int		i;
	double	d;
	float	f;
}	t_conversion;

class ScalarConverter
{
public:
	static void	convert(string &toConvert);
};
