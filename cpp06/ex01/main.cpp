#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int	main()
{
	Data			original("Hello, 42!");
	uintptr_t		raw = Serializer::serialize(&original);
	Data			*deserialized = Serializer::deserialize(raw);

	std::cout << "original address:     " << &original << std::endl;
	std::cout << "deserialized address: " << deserialized << std::endl;
	std::cout << "same address? " << (deserialized == &original ? "yes" : "no") << std::endl;
	std::cout << "info: " << deserialized->getInfo() << std::endl;
	std::cout << "len:  " << deserialized->getLen() << std::endl;

	return (0);
}
