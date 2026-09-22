#pragma once

#include <stdint.h>
#include "Data.hpp"

class Data;

class Serializer
{	
public:
	static uintptr_t	serialize(Data* ptr);
	static Data*	deserialize(uintptr_t raw);
};

