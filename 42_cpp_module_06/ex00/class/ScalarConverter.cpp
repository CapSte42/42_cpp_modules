#include "../includes/ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <limits>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <stdexcept>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &) {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) { return *this; }

void ScalarConverter::convert(const std::string &literal)
{
	double value;
	try
	{
		value = convertToDouble(literal);
	}
	catch (const std::exception &e)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}

	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}

double ScalarConverter::convertToDouble(const std::string &literal)
{
	if (literal.length() == 1 && !std::isdigit(literal[0]))
		return static_cast<double>(literal[0]);

	char *endptr = NULL;
	double d = std::strtod(literal.c_str(), &endptr);

	if (*endptr == 'f' && *(endptr + 1) == '\0')
		return d;
	else if (*endptr == '\0')
		return d;
	else if (literal == "nan" || literal == "nanf")
		return std::numeric_limits<double>::quiet_NaN();
	else if (literal == "+inf" || literal == "+inff")
		return std::numeric_limits<double>::infinity();
	else if (literal == "-inf" || literal == "-inff")
		return -std::numeric_limits<double>::infinity();
	else
		throw std::invalid_argument("Invalid literal");

	return d;
}

void ScalarConverter::printChar(double value)
{
	std::cout << "char: ";
	try
	{
		char c = convertToChar(value);
		std::cout << "'" << c << "'" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::string err = e.what();
		if (err == "Non displayable character")
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "impossible" << std::endl;
	}
}

void ScalarConverter::printInt(double value)
{
	std::cout << "int: ";
	try
	{
		int i = convertToInt(value);
		std::cout << i << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "impossible" << std::endl;
	}
}

void ScalarConverter::printFloat(double value)
{
	std::cout << "float: ";
	float f = static_cast<float>(value);

	if (std::isnan(f))
		std::cout << "nanf" << std::endl;
	else if (std::isinf(f))
		std::cout << (f > 0 ? "+inff" : "-inff") << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

void ScalarConverter::printDouble(double value)
{
	std::cout << "double: ";
	if (std::isnan(value))
		std::cout << "nan" << std::endl;
	else if (std::isinf(value))
		std::cout << (value > 0 ? "+inf" : "-inf") << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << value << std::endl;
}

char ScalarConverter::convertToChar(double value)
{
	if (std::isnan(value) || std::isinf(value) ||
		value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
		throw std::range_error("Impossible to convert to char");

	char c = static_cast<char>(value);
	if (!std::isprint(c))
		throw std::runtime_error("Non displayable character");

	return c;
}

int ScalarConverter::convertToInt(double value)
{
	if (std::isnan(value) || std::isinf(value) ||
		value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
		throw std::range_error("Impossible to convert to int");

	return static_cast<int>(value);
}

float ScalarConverter::convertToFloat(double value)
{
	return static_cast<float>(value);
}
