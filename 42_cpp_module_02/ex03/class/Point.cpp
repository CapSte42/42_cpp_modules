/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 22:22:11 by smontuor          #+#    #+#             */
/*   Updated: 2024/09/04 10:28:07 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

Point::Point() : _x(0), _y(0)
{
	dbgPrint("Default constructor called");
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
	dbgPrint("Float constructor called");
}

Point::Point(const Point &src) : _x(src._x), _y(src._y)
{
	dbgPrint("Copy constructor called");
}

Point::~Point()
{
	dbgPrint("Destructor called");
}

Point &Point::operator=(const Point &src)
{
	dbgPrint("Copy assignment operator called");
	// Siccome x e y sono const, non si dovrebbero poter riassegnare
	// per farlo bisognerebbe aggirare la constness, facendo perdere il senso di avere x e y const
	if (this != &src)
	{

	}
	return *this;
}

Fixed const &Point::getX(void) const
{
	dbgPrint("getX member function called");
	return _x;
}

Fixed const &Point::getY(void) const
{
	dbgPrint("getY member function called");
	return _y;
}
