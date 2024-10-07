#include "../includes/Bureaucrat.hpp"
#include <iostream>

int main ()
{
	int grade = 0;
	std::cin >> grade;
	try {
	{
		Bureaucrat b1("b1", grade);
	}
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}