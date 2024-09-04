/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 11:17:04 by smontuor          #+#    #+#             */
/*   Updated: 2024/09/03 17:34:30 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include <cmath>

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
	_raw = value << _fractionalBits; // Sposta il valore intero di _fractionalBits a sinistra
}

Fixed::Fixed(const float value)
{
	dbgPrint("Float constructor called");
	_raw = static_cast<int>(roundf(value * (1 << _fractionalBits))); // Converti il float in fixed-point
}

Fixed &Fixed::operator=(const Fixed &src)
{
	dbgPrint("Copy assignment operator called");
	if (this != &src)
		_raw = src._raw;
	return *this;
}

Fixed::~Fixed()
{
	dbgPrint("Destructor called");
}

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

float Fixed::toFloat(void) const
{
	return static_cast<float>(_raw) / (1 << _fractionalBits); // Converti il fixed-point in float
}

int Fixed::toInt(void) const
{
	return _raw >> _fractionalBits; // Sposta il valore a destra per ottenere l'intero
}

void dbgPrint(const std::string &msg)
{
	if (DEBUG == 1)
		std::cout << msg << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat(); // Stampa il valore come float
	return out;
}
