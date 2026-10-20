#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int	main()
{
	Data			original;
	original.speedWalk = 5;
	original.speedRun = 12;

	uintptr_t		raw = Serializer::serialize(&original);
	Data			*deserialized = Serializer::deserialize(raw);

	std::cout << "original address:     " << &original << std::endl;
	std::cout << "deserialized address: " << deserialized << std::endl;
	std::cout << "same address? " << (deserialized == &original ? "yes" : "no") << std::endl;
	std::cout << "speedWalk: " << deserialized->speedWalk << std::endl;
	std::cout << "speedRun:  " << deserialized->speedRun << std::endl;

	return (0);
}
