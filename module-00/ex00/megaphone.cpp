#include <iostream>
#include <string.h>

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		std::string	text;

		for (int i = 1; i < argc; ++i)
		{
			std::string	s = argv[i];

			for (std::size_t j = 0; j < s.length(); ++j)
			{
				s[j] = std::toupper(s[j]);
			}
			text += s;
			if (i != argc - 1)
				text += " ";
		}
		std::cout << text << std::endl;
	}
}
