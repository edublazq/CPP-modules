#include "MutantStack.hpp"
#include <iostream>
#include <string>
#include <stack>
#include <list>

int	main(void)
{
	std::cout << "-- subject example --" << std::endl;
	MutantStack<int>	mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int>	s(mstack);

	std::cout << "-- empty stack iteration --" << std::endl;
	MutantStack<int>	empty;
	std::cout << std::boolalpha << (empty.begin() == empty.end()) << std::endl;

	std::cout << "-- post-increment / post-decrement --" << std::endl;
	MutantStack<int>	nums;
	for (int i = 1; i <= 5; i++)
		nums.push(i);
	MutantStack<int>::iterator nit = nums.begin();
	MutantStack<int>::iterator prev = nit++;
	std::cout << "prev=" << *prev << " now=" << *nit << std::endl;
	MutantStack<int>::iterator after = nit--;
	std::cout << "after=" << *after << " now=" << *nit << std::endl;

	std::cout << "-- reverse traversal with iterators --" << std::endl;
	MutantStack<int>::iterator rit = nums.end();
	--rit;
	for (; rit != nums.begin(); --rit)
		std::cout << *rit << " ";
	std::cout << *rit << std::endl;

	std::cout << "-- copy constructor keeps independent data --" << std::endl;
	MutantStack<int>	copyStack(nums);
	copyStack.push(42);
	std::cout << "original size: " << nums.size() << std::endl;
	std::cout << "copy size: " << copyStack.size() << std::endl;

	std::cout << "-- assignment operator keeps independent data --" << std::endl;
	MutantStack<int>	assignStack;
	assignStack = nums;
	assignStack.pop();
	std::cout << "original size: " << nums.size() << std::endl;
	std::cout << "assigned size: " << assignStack.size() << std::endl;

	std::cout << "-- works with std::string --" << std::endl;
	MutantStack<std::string>	strStack;
	strStack.push("foo");
	strStack.push("bar");
	strStack.push("baz");
	for (MutantStack<std::string>::iterator sit = strStack.begin();
		sit != strStack.end(); ++sit)
		std::cout << *sit << " ";
	std::cout << std::endl;

	std::cout << "-- std::stack still behaves like a stack --" << std::endl;
	while (!mstack.empty())
	{
		std::cout << mstack.top() << " ";
		mstack.pop();
	}
	std::cout << std::endl;

	std::cout << "-- comparison against std::list-based stack --" << std::endl;
	MutantStack<int>	listLike;
	std::list<int>		reference;
	for (int i = 0; i < 5; i++)
	{
		listLike.push(i);
		reference.push_back(i);
	}
	MutantStack<int>::iterator			lit = listLike.begin();
	std::list<int>::iterator			refIt = reference.begin();
	bool								same = true;
	for (; lit != listLike.end() && refIt != reference.end(); ++lit, ++refIt)
	{
		if (*lit != *refIt)
			same = false;
	}
	std::cout << "sequences match: " << same << std::endl;

	return (0);
}
