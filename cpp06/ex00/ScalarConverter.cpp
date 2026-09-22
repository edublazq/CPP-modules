#include "ScalarConverter.hpp"

e_type	getType(string &toConvert)
{
	char	*end;
	double	strNum = strtod(toConvert.c_str(), &end);
	if (end == toConvert.c_str())
		return (INVALID);
	if (*end != '\0')
	{
		if (*end == 'f' && *(end + 1) == '\0')
			return (FLOAT);
		else
		{
			if (!std::strcmp(end, "+inf") || !std::strcmp(end, "-inf") || !std::strcmp(end, "nan"))
				return (PSEUDO);
			if (strNum == 0 && *(end + 1) == '\0')
				return (CHAR);
		}
		return (INVALID);
	}
	if ((static_cast<int>(strNum) / strNum) != 1)
		return (DOUBLE);
	return (INT);
}

int	charConversion(string &toConvert, t_conversion &conversion)
{
	conversion.c = toConvert[0];
	conversion.i = static_cast<int>(conversion.c);
	conversion.d = static_cast<double>(conversion.c);
	conversion.f = static_cast<float>(conversion.c);
	return (EXIT_SUCCESS);
}

int	doubleConversion(string &toConvert, t_conversion &conversion)
{
	conversion.d = strtod(toConvert.c_str(), NULL);
	conversion.f = static_cast<float>(conversion.d);
	conversion.c = static_cast<char>(conversion.d);
	conversion.i = static_cast<int>(conversion.d);
	return (EXIT_SUCCESS);
}

int	floatConversion(string &toConvert, t_conversion &conversion)
{
	conversion.f = strtof(toConvert.c_str(), NULL);
	conversion.d = static_cast<double>(conversion.f);
	conversion.c = static_cast<char>(conversion.f);
	conversion.i = static_cast<int>(conversion.f);
	return (EXIT_SUCCESS);
}

int	intConversion(string &toConvert, t_conversion &conversion)
{
	conversion.i = atoi(toConvert.c_str());
	conversion.d = static_cast<double>(conversion.i);
	conversion.c = static_cast<char>(conversion.i);
	conversion.f = static_cast<float>(conversion.i);
	return (EXIT_SUCCESS);
}

void	pseudo(string &toConvert)
{
	if (toConvert == "nan")
	{
		cout << "char: impossible" << endl;
		cout << "int: impossible" << endl;
		cout << "float: nanf" << endl;
		cout << "double: nan" << endl;
	}
	else if(toConvert == "+inf")
	{
		cout << "char: impossible" << endl;
		cout << "int: impossible" << endl;
		cout << "float: +inf" << endl;
		cout << "double: +inf" << endl;	
	}
	else
	{
		cout << "char: impossible" << endl;
		cout << "int: impossible" << endl;
		cout << "float: -inf" << endl;
		cout << "double: -inf" << endl;
	}
}

void	printConversion(t_conversion &conversion)
{
	if (conversion.c < 20)
		cout << "char: Non displayable" << endl;
	else
		cout << "char: " << conversion.c << endl;
	cout << "int: " << conversion.i << endl;
	cout << "float: " << conversion.f << "f" << endl;
	cout << "double: " << conversion.d << endl;
}

void	ScalarConverter::convert(string &toConvert)
{
	t_conversion	conversion;
	e_type	type = getType(toConvert);
	if (type == INVALID)
	{
		cout << "Invalid conversion" << endl;
		return ;
	}
	if (type == CHAR)
		charConversion(toConvert, conversion);
	else if (type == INT)
		intConversion(toConvert, conversion);
	else if (type == FLOAT)
		floatConversion(toConvert, conversion);
	else if (type == DOUBLE)
		doubleConversion(toConvert, conversion);
	else if (type == PSEUDO)
	{
		pseudo(toConvert);
		return ;
	}
	printConversion(conversion);
}
