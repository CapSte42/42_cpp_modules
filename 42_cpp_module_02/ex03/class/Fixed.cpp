/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 11:17:04 by smontuor          #+#    #+#             */
/*   Updated: 2024/09/03 16:26:00 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

/*-------------------------- Constructors --------------------------------------*/
//	Default constructor
//	Copy constructor
//	Int constructor
//	Float constructor
//	Destructor
/*------------------------------------------------------------------------------*/
Fixed::Fixed() : _raw(0)
{
	dbgPrint("Default constructor called");
}

Fixed::Fixed(const Fixed &src) : _raw(src._raw)
{
	dbgPrint("Copy constructor called");
}

Fixed::Fixed(const int value)
{
	dbgPrint("Int constructor called");
	_raw = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
	dbgPrint("Float constructor called");
	_raw = static_cast<int>(roundf(value * (1 << _fractionalBits)));
}

Fixed::~Fixed()
{
	dbgPrint("Destructor called");
}
/*-------------------------- Operators -----------------------------------------*/
//	Overload operator = (assignation)
//	Overload operator > (greater than)
//	Overload operator < (less than)
//	Overload operator >= (greater than or equal to)
//	Overload operator <= (less than or equal to)
//	Overload operator == (equal to)
//	Overload operator != (not equal to)
/*------------------------------------------------------------------------------*/


Fixed &Fixed::operator=(const Fixed &src)
{
	dbgPrint("Copy assignment operator called");
	if (this != &src)
		_raw = src._raw;
	return *this;
}

bool Fixed::operator>(const Fixed &src) const
{
	dbgPrint("Greater than operator called");
	return _raw > src._raw;
}

bool Fixed::operator<(const Fixed &src) const
{
	dbgPrint("Less than operator called");
	return _raw < src._raw;
}

bool Fixed::operator>=(const Fixed &src) const
{
	dbgPrint("Greater than or equal to operator called");
	return _raw >= src._raw;
}

bool Fixed::operator<=(const Fixed &src) const
{
	dbgPrint("Less than or equal to operator called");
	return _raw <= src._raw;
}

bool Fixed::operator==(const Fixed &src) const
{
	dbgPrint("Equal to operator called");
	return _raw == src._raw;
}

bool Fixed::operator!=(const Fixed &src) const
{
	dbgPrint("Not equal to operator called");
	return _raw != src._raw;
}

/*-------------------------- Getters & Setters -------------------------------- */
//	getRawBits
//	setRawBits
/*------------------------------------------------------------------------------*/
int	Fixed::getRawBits(void) const
{
	dbgPrint("getRawBits member function called");
	return _raw;
}

void Fixed::setRawBits(int const raw)
{
	dbgPrint("setRawBits member function called");
	_raw = raw;
}

/*-------------------------- Member functions --------------------------------- */
//	toInt
//	toFloat
/*------------------------------------------------------------------------------*/
float Fixed::toFloat(void) const
{
	return static_cast<float>(_raw) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
	return _raw >> _fractionalBits;
}

/*-------------------------- Arithmetic operators ------------------------------*/
//	Overload operator + (addition)
//	Overload operator - (subtraction)
//	Overload operator * (multiplication)
//	Overload operator / (division)
/*------------------------------------------------------------------------------*/

Fixed Fixed::operator+(const Fixed &src) const
{
	dbgPrint("Addition operator called");
	return Fixed(this->toFloat() + src.toFloat());
}

Fixed Fixed::operator-(const Fixed &src) const
{
	dbgPrint("Subtraction operator called");
	return Fixed(this->toFloat() - src.toFloat());
}

Fixed Fixed::operator*(const Fixed &src) const
{
	dbgPrint("Multiplication operator called");
	return Fixed(this->toFloat() * src.toFloat());
}

Fixed Fixed::operator/(const Fixed &src) const
{
	dbgPrint("Division operator called");
	if (src._raw == 0)
	{
		std::cerr << "Error: division by zero" << std::endl;
		return Fixed(0);
	}
	return Fixed(this->toFloat() / src.toFloat());
}

/*-------------------------- Increment & Decrement -----------------------------*/
//	Overload operator ++ (pre-increment)
//	Overload operator ++ (post-increment)
//	Overload operator -- (pre-decrement)
//	Overload operator -- (post-decrement)
/*------------------------------------------------------------------------------*/

Fixed &Fixed::operator++(void)
{
	dbgPrint("Pre-increment operator called");
	_raw++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	dbgPrint("Post-increment operator called");
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed &Fixed::operator--(void)
{
	dbgPrint("Pre-decrement operator called");
	_raw--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	dbgPrint("Post-decrement operator called");
	Fixed tmp(*this);
	operator--();
	return tmp;
}

/*-------------------------- Static member functions ---------------------------*/
//	min
//	max
//  const min
//  const max
/*------------------------------------------------------------------------------*/

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	dbgPrint("min static member function called");
	return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	dbgPrint("max static member function called");
	return a > b ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	dbgPrint("const min static member function called");
	return a < b ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	dbgPrint("const max static member function called");
	return a > b ? a : b;
}

Fixed Fixed::abs(void) const
{
	// if (area < 0)
	// 	area = area * Fixed(-1);
	dbgPrint("abs member function called");
	return Fixed(this->_raw < 0 ? -this->toFloat() : this->toFloat());
}

/* ************************************************************************** */
void dbgPrint(const std::string &msg)
{
	if (DEBUG == 1)
		std::cout << msg << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}
