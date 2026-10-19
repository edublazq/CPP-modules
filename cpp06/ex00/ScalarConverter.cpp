#include "ScalarConverter.hpp"
#include <cctype>
#include <cmath>
#include <limits>

static bool	isPseudo(const string &s)
{
	return (s == "nan" || s == "+inf" || s == "-inf"
		|| s == "nanf" || s == "+inff" || s == "-inff");
}

static e_type	getType(const string &toConvert)
{
	if (toConvert.empty())
		return (INVALID);
	if (isPseudo(toConvert))
		return (PSEUDO);
	if (toConvert.length() == 1 && !std::isdigit(static_cast<unsigned char>(toConvert[0])))
		return (CHAR);
	char	*end;
	double	strNum = strtod(toConvert.c_str(), &end);
	if (end == toConvert.c_str())
		return (INVALID);
	if (*end != '\0')
	{
		if (*end == 'f' && *(end + 1) == '\0')
			return (FLOAT);
		return (INVALID);
	}
	if (strNum >= INT_MIN && strNum <= INT_MAX
		&& strNum == static_cast<double>(static_cast<int>(strNum)))
		return (INT);
	return (DOUBLE);
}

static bool	isFinite(double d)
{
	return (d == d && d <= DBL_MAX && d >= -DBL_MAX);
}

static void	printChar(double d)
{
	cout << "char: ";
	if (!isFinite(d) || d < 0 || d > 127)
		cout << "impossible";
	else if (d < 32 || d >= 127)
		cout << "Non displayable";
	else
		cout << "'" << static_cast<char>(d) << "'";
	cout << endl;
}

static void	printInt(double d)
{
	cout << "int: ";
	if (!isFinite(d) || d < INT_MIN || d > INT_MAX)
		cout << "impossible";
	else
		cout << static_cast<int>(d);
	cout << endl;
}

static void	printFloat(double d)
{
	float	f = static_cast<float>(d);

	cout << "float: ";
	if (isFinite(d) && (d < -FLT_MAX || d > FLT_MAX))
		cout << "impossible";
	else if (f != f)
		cout << "nanf";
	else if (f > FLT_MAX)
		cout << "+inff";
	else if (f < -FLT_MAX)
		cout << "-inff";
	else
	{
		if (std::floor(f) == f)
			cout << std::fixed << std::setprecision(1);
		else
			cout << std::setprecision(FLT_DIG);
		cout << f << "f";
		cout.unsetf(std::ios::fixed);
	}
	cout << endl;
}

static void	printDouble(double d)
{
	cout << "double: ";
	if (d != d)
		cout << "nan";
	else if (d > DBL_MAX)
		cout << "+inf";
	else if (d < -DBL_MAX)
		cout << "-inf";
	else
	{
		if (std::floor(d) == d)
			cout << std::fixed << std::setprecision(1);
		else
			cout << std::setprecision(DBL_DIG);
		cout << d;
		cout.unsetf(std::ios::fixed);
	}
	cout << endl;
}

static void	printConversion(double d)
{
	printChar(d);
	printInt(d);
	printFloat(d);
	printDouble(d);
}

void	ScalarConverter::convert(string &toConvert)
{
	e_type	type = getType(toConvert);
	double	d;

	if (type == INVALID)
	{
		cout << "Invalid conversion" << endl;
		return ;
	}
	if (type == CHAR)
		d = static_cast<double>(static_cast<unsigned char>(toConvert[0]));
	else if (type == FLOAT)
		d = static_cast<double>(strtof(toConvert.c_str(), NULL));
	else
		d = strtod(toConvert.c_str(), NULL);
	printConversion(d);
}
