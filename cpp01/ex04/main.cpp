#include <fstream>
#include <iostream>
#include <string>

using std::string;
using std::ofstream;
using std::ifstream;
using std::streampos;
using std::cout;
using std::cerr;
using std::endl;

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		cerr << "./sed \"filename\" \"replace1\" \"replace2\"" << endl;
		return (1);
	}

	char		buf;
	string		search = av[2];
	string		change = av[3];
	string		comp;
	streampos	save;
	ifstream	file(av[1]);
	ofstream	outfile((string)(av[1]) + "_out");

	if (!file.is_open() || !outfile.is_open())
	{
		cerr << "Error opening file" << endl;
		return (2);
	}
	while (file.get(buf))
	{
		if (buf == search[0])
		{
			save = file.tellg();

			comp = buf;
			comp.resize(search.length());

			file.read(&comp[1], search.length() - 1);

			if (comp == search)
				outfile << change;
			else
			{
				file.clear();
				file.seekg(save);
				outfile << buf;
			}
		}
		else
			outfile << buf;
	}
	return (0);
}
