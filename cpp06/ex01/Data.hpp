#pragma once

#include <stdint.h>
#include <string>

using std::string;

class Data
{
private:
	char		*info;
	uint64_t	len;

public:
	Data();
	Data(const string &str);
	Data(const Data &other);
	Data	&operator=(const Data &other);
	~Data();

	const char	*getInfo() const;
	uint64_t	getLen() const;
	void		setInfo(const string &str);
};
