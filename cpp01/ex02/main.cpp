#include <iostream>

using std::string;
using std::cout;
using std::endl;

int	main(void)
{
	string	str = "HI THIS IS BRAIN";
	string	&strRef = str;
	string	*strAddr = &str;

	cout << &str << endl;
	cout << &strRef << endl;
	cout << strAddr << endl;

	cout << str << endl;
	cout << strRef << endl;
	cout << *strAddr << endl;
}
