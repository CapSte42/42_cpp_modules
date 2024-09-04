/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 11:17:04 by smontuor          #+#    #+#             */
/*   Updated: 2024/09/04 12:36:58 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _raw(0)
{
	dbgPrint("Default constructor called");
}

Fixed::Fixed(const Fixed &src) : _raw(src._raw)
{
	dbgPrint("Copy constructor called");
}

Fixed &Fixed::operator=(const Fixed &src)
{
	dbgPrint("Assignation operator called");
	if (this != &src)
		_raw = src._raw;
	return *this;
}

Fixed::~Fixed()
{
	dbgPrint("Destructor called");
}

int		Fixed::getRawBits(void) const
{
	dbgPrint("getRawBits member function called");
	return _raw;
}

void	Fixed::setRawBits(int const raw)
{
	dbgPrint("setRawBits member function called");
	_raw = raw;
}

void	dbgPrint(const std::string &msg)
{
	if (DEBUG == 1)
		std::cout << msg << std::endl;
}
