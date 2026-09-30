#pragma once

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <map>
#include <algorithm>

using std::cout;
using std::ifstream;
using std::istringstream;
using std::string;
using std::getline;
using std::endl;

class BitcoinExchange
{
private:
	std::map<string, float>	_database;
public:
	BitcoinExchange();
	BitcoinExchange(char *av);
	BitcoinExchange(const BitcoinExchange& copy);
	BitcoinExchange& operator=(const BitcoinExchange& copy);
	~BitcoinExchange();

	float	exchange(string &date, float n);
};
