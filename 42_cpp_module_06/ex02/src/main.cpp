#include "../includes/Functions.hpp"
#include <iostream>

int main()
{
	Base* p = generate();

	std::cout << "Identificazione tramite puntatore:" << std::endl;
	identify(p);

	std::cout << "Identificazione tramite riferimento:" << std::endl;
	identify(*p);

	delete p;

	return 0;
}
