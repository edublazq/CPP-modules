#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		_templates[i] = NULL;
	_n_templates = 0;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	for (int i = 0; i < 4; i++)
		_templates[i] = other._templates[i];
	_n_templates = other._n_templates;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
			_templates[i] = other._templates[i];
		_n_templates = other._n_templates;
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	cout << "MateriaSource destructor called" << endl;
}

void	MateriaSource::learnMateria(AMateria *m)
{
	if (_n_templates >= 4)
	{
		std::cerr << "No space left for new materias" << endl;
		return ;
	}
	_templates[_n_templates] = m;
	_n_templates++;
}

AMateria*	MateriaSource::createMateria(string const &type)
{
	for (size_t i = 0; i < _n_templates; i++)
	{
		if (_templates[i]->getType() == type)
			return (_templates[i]->clone());
	}
	return (NULL);
}
