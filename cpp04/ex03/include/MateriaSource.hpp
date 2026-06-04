#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*_templates[4];
		unsigned int	_n_templates;
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &other);
		MateriaSource& operator=(const MateriaSource &other);
		~MateriaSource();

		void		learnMateria(AMateria *m);
		AMateria*	createMateria(string const &type);
};
