#pragma once

# include <string>
# include <sstream>
# include <iomanip>
# include <iostream>
# include <limits.h>
# include <cstdlib>
# include <cstring>
# include <cfloat>

using std::string;
using std::cout;
using std::endl;

enum	e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO,
	INVALID
};

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& toCopy);
	ScalarConverter& operator=(const ScalarConverter& toCopy);
	~ScalarConverter();
public:
	static void	convert(string &toConvert);
};
