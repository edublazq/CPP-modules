#pragma once

#include <stdexcept>
#include <list>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T& container, int value);

#include "easyfind.tpp"
