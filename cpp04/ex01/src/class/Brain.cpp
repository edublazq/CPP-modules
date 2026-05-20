#include "Brain.hpp"

Brain::Brain()
{
	cout << "Brain constructor called" << endl;
}

Brain::Brain(const Brain &toCopy)
{
	for (size_t i = 0; i < 100; i++)
		_ideas[i] = toCopy._ideas[i];
	cout << "Brain copy constructor called" << endl;
}

Brain&	Brain::operator=(const Brain &toCopy)
{
	if (this != &toCopy)
	{
		for (size_t i = 0; i < 100; i++)
			_ideas[i] = toCopy._ideas[i];	
	}
	return (*this);
}

Brain::~Brain()
{
	cout << "Brain destructor called" << endl;
}

void	Brain::setIdea(size_t i, const string &idea)
{
	if (i < 100)
		_ideas[i] = idea;
	else
		throw std::out_of_range("iterator out of range");
}

string	Brain::getIdea(size_t i) const
{
	if (i < 100)
		return (_ideas[i]);
	else
		throw std::out_of_range("iterator out of range");
}
