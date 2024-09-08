/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor42 <smontuor42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:14:05 by smontuor42        #+#    #+#             */
/*   Updated: 2024/09/08 18:49:38 by smontuor42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include <iostream>

Animal::Animal() : _type("Animal")
{
	dbgprint(BOLDGREEN + _type, "'s default constructor called");
}

Animal::Animal(std::string type) : _type(type)
{
	std::string defaultType = "Animal";
	dbgprint(BOLDYELLOW + defaultType, "'s type constructor called");
}

Animal::Animal(const Animal &src) : _type(src._type)
{
	dbgprint(BOLDBLUE + _type, "'s copy constructor called");
}

Animal::~Animal()
{
	std::string defaultType = "Animal";
	dbgprint(BOLDRED + defaultType, "'s destructor called");
}

Animal	&Animal::operator=(const Animal &rhs)
{
	_type = rhs._type;
	return *this;
}

std::string		Animal::getType() const
{
	return _type;
}

void			Animal::setType(std::string type)
{
	_type = type;
}

void			Animal::dbgprint(std::string type, std::string msg) const
{
	if (DEBUG)
		std::cout << type << msg << RESET << std::endl;
}

void			Animal::print(std::string type, std::string msg) const
{
	std::cout << type << msg << RESET << std::endl;
}
