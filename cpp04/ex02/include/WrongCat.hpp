#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat &toCopy);
		~WrongCat();
		WrongCat& operator=(const WrongCat &toCopy);
};

