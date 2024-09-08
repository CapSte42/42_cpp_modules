/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor42 <smontuor42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 23:37:28 by smontuor42        #+#    #+#             */
/*   Updated: 2024/09/08 23:46:07 by smontuor42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice")
{
	dbgprint(BOLDGREEN + getType(), "'s default constructor called");
}

Ice::Ice(const Ice &src) : AMateria(src)
{
	dbgprint(BOLDBLUE + getType(), "'s copy constructor called");
}

Ice::~Ice()
{
	dbgprint(BOLDRED + getType(), "'s destructor called");
}

Ice		&Ice::operator=(const Ice &rhs)
{
	AMateria::operator=(rhs);
	return *this;
}

AMateria	*Ice::clone() const
{
	return new Ice(*this);
}

void		Ice::use(ICharacter &target)
{
	print(BOLDWHITE , "\"* shoots an ice bolt at " + target.getName() + " *\"");
}
