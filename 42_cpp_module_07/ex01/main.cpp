#include "includes/iter.hpp"
#include <iostream>

void print(std::string const &x)
{
	std::cout << x << " ";
}

int main()
{
	// Array di interi
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intArraySize = sizeof(intArray) / sizeof(intArray[0]);

	std::cout << "Integer array:\n";
	iter(intArray, intArraySize, print<int>); // Usa la funzione generica

	std::cout << "\n";

	// Array di stringhe
	std::string strArray[] = {"Hello", "World", "!"};
	size_t strArraySize = sizeof(strArray) / sizeof(strArray[0]);

	std::cout << "String array:\n";
	iter(strArray, strArraySize, static_cast<void(*)(const std::string&)>(&print)); // Specifica l'overload
	std::cout << "\n";

	// Array di caratteri
	char charArray[] = {'A', 'B', 'C', 'D'};
	size_t charArraySize = sizeof(charArray) / sizeof(charArray[0]);

	std::cout << "Character array:\n";
	iter(charArray, charArraySize, print<char>); // Usa la funzione generica

	return (0);
}
