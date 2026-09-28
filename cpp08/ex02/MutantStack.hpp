#pragma once

#include <stack>
#include <algorithm>

template <typename T> class MutantStack : public std::stack<T>
{
public:
	typedef typename std::deque<T>::iterator iterator;
	iterator begin();
	iterator end();
};

#include "MutantStack.tpp"
