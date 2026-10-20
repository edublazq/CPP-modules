#pragma once

#include <stdint.h>
#include "Data.hpp"

class Serializer
{
private:
	Serializer();
	Serializer(const Serializer& toCopy);
	Serializer& operator=(const Serializer& toCopy);
	~Serializer();
public:
	static uintptr_t	serialize(Data* ptr);
	static Data*	deserialize(uintptr_t raw);
};

