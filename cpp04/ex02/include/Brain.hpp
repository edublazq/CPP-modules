#pragma once

#include <iostream>
#include <stdexcept>

using std::string;
using std::endl;
using std::cout;

class Brain
{
private:
	string	_ideas[100];
public:
	Brain();
	Brain(const Brain &toCopy);
	Brain& operator=(const Brain &toCopy);
	~Brain();

	void	setIdea(size_t i, const string &idea);
	string	getIdea(size_t i) const;
};

