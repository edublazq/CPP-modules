#include "Phonebook.hpp"

std::string formatColumn(const std::string& str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}
