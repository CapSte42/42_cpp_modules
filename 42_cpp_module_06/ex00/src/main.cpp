#include "../includes/ScalarConverter.hpp"
#include <iostream>
#include <string>

void performStandardTests()
{
	std::string testCases[] = {
		"0",
		"nan",
		"+inf",
		"-inf",
		"42.0f",
		"a",
		"NonPrintableChar",
		"9999999999999999999999999999999999999999",
		"2147483647",         // Max int
		"2147483648",         // Max int + 1
		"-2147483648",        // Min int
		"-2147483649",        // Min int - 1
		"1.7976931348623157e+308",  // Max double
		"1.7976931348623159e+308",  // Max double + epsilon
		"-1.7976931348623157e+308", // Min double
		"-1.7976931348623159e+308", // Min double - epsilon
		"2.22507e-308",       // Min positive double
		"-2.22507e-308",      // Max negative double
		"3.40282e+38f",       // Max float
		"3.40283e+38f",       // Max float + epsilon
		"1e-50",              // Underflow in float
		"hello",              // Invalid input
		""                    // Empty string
	};

	for (size_t i = 0; i < sizeof(testCases)/sizeof(testCases[0]); ++i)
	{
		std::cout << "Test case " << i + 1 << ": \"" << testCases[i] << "\"" << std::endl;
		ScalarConverter::convert(testCases[i]);
		std::cout << std::endl;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		ScalarConverter::convert(argv[1]);
	}
	else
	{
		char choice;
		std::cout << "No input provided. Do you want to run standard tests? (y/n): ";
		std::cin >> choice;

		if (choice == 'y' || choice == 'Y')
		{
			performStandardTests();
		}
		else
		{
			std::cout << "Usage: ./convert <literal>" << std::endl;
			return 1;
		}
	}

	return 0;
}
