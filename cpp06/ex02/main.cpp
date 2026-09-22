#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::endl;

Base*	generate(void)
{
	Base	*base;
	int 	seed = std::rand() % 3 + 1;
	switch(seed)
	{
		case 1:
			base = new A();
			break ;
		case 2:
			base = new B();
			break ;
		case 3:
			base = new C();
	}
	return (base);
}

void	identify(Base* p)
{
	A* a = NULL;
	B* b = NULL;
	C* c = NULL;
	try
	{
		a = dynamic_cast<A*>(p);
	}
	catch(const std::exception& e){}
	try
	{
		b = dynamic_cast<B*>(p);
	}
	catch(const std::exception& e){}
	try
	{
		c = dynamic_cast<C*>(p);
	}
	catch(const std::exception& e){}
	cout << "Type is: ";
	if (!a && !b)
		cout << "C";
	else if (!b && !c)
		cout << "A";
	else
		cout << "B";
	cout << endl;
}

void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		cout << "Type is: A" << endl;
	}
	catch(const std::exception& e){}
	try
	{
		(void)dynamic_cast<B&>(p);
		cout << "Type is: B" << endl;
	}
	catch(const std::exception& e){}
	try
	{
		(void)dynamic_cast<C&>(p);
		cout << "Type is: C" << endl;
	}
	catch(const std::exception& e){}
}

int	main()
{
	std::srand(std::time(NULL));
	Base *p = generate();

	identify(p);
	identify(*p);

	delete p;
	return (0);
}
