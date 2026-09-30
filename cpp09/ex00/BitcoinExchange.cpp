#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::ifstream file("data.csv");
	std::string line;

    if (!file.is_open())
        throw std::runtime_error("Could not open data.csv");
    if (!std::getline(file, line) || line != "date,exchange_rate")
        throw std::runtime_error("File structure not ok");
    while (std::getline(file, line))
    {
        if (line.empty())
			continue ;
        std::istringstream iss(line);
        std::string date, value;

        if (!std::getline(iss, date, ',') || !std::getline(iss, value))
            throw std::runtime_error("Line found not okay -> " + line);

        if (date.size() != 10 || date[4] != '-' || date[7] != '-')
            throw std::runtime_error("Date found not okay -> " + date);

        _database[date] = std::atof(value.c_str());
    }
    file.close();
}

BitcoinExchange::~BitcoinExchange()
{
	_database.clear();
}

BitcoinExchange::BitcoinExchange(char *av)
{
	std::ifstream file(av);
	std::string line;

	if (!file.is_open())
		throw std::runtime_error("Could not open selected file");
	if (!std::getline(file, line) || line != "date,exchange_rate")
		throw std::runtime_error("File structure not ok");
	while (std::getline(file, line))
	{
		if (line.empty())
			continue ;
		std::istringstream iss(line);
		std::string date, value;

		if (!std::getline(iss, date, ',') || !std::getline(iss, value))
			throw std::runtime_error("Line found not okay -> " + line);

		if (date.size() != 10 || date[4] != '-' || date[7] != '-')
			throw std::runtime_error("Date found not okay -> " + date);

		_database[date] = std::atof(value.c_str());
	}
	file.close();
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& copy)
{
	this->_database = copy._database;
	return (*this);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy): _database(copy._database)
{}

float	BitcoinExchange::exchange(string &date, float n)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		throw std::runtime_error("Date selected not okay");
	
	std::map<string, float>::iterator it = _database.find(date);
	if (it != _database.end())
		return (_database[date] * n);
	it = _database.lower_bound(date);
	if (it == _database.end() || it->first != date)
	{
		if (it == _database.begin())
			throw std::runtime_error("Error: no data available for or before" + date);
		--it;
		return ((it->second) * n);
	}
	throw std::runtime_error("Strange error");
}
