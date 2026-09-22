#include "Data.hpp"
#include <cstring>

Data::Data() : info(NULL), len(0)
{
}

Data::Data(const string &str) : info(NULL), len(0)
{
	this->setInfo(str);
}

Data::Data(const Data &other) : info(NULL), len(0)
{
	*this = other;
}

Data	&Data::operator=(const Data &other)
{
	if (this == &other)
		return (*this);
	delete[] info;
	info = NULL;
	len = other.len;
	if (other.info)
	{
		info = new char[len + 1];
		std::memcpy(info, other.info, len + 1);
	}
	return (*this);
}

Data::~Data()
{
	delete[] info;
}

const char	*Data::getInfo() const
{
	return (info);
}

uint64_t	Data::getLen() const
{
	return (len);
}

void	Data::setInfo(const string &str)
{
	delete[] info;
	len = str.size();
	info = new char[len + 1];
	std::memcpy(info, str.c_str(), len + 1);
}
