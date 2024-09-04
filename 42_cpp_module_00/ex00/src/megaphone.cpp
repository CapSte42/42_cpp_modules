#include <iostream>
#include <sstream>
#include <string>

void	printLoud(int ac, char **av, std::ostream& os = std::cout)
{
	std::stringstream	ss;
	std::string			str;
	int					strLen;

	if (ac == 1)
	{
		ss << " * LOUD AND UNBEARABLE FEEDBACK NOISE *";
		goto exit;
	}

	for (int i = 1; i < ac; i++)
	{
		std::string a = "ciao";
		str = av[i];
		strLen = str.length();
		for (int j = 0; j < strLen; j++)
		{
			ss << (char)toupper(str[j]);
		}
	}
	exit :
	os << ss.str() << std::endl;
}

int	main(int ac, char **av)
{
	printLoud(ac, av);
	return (0);
}
