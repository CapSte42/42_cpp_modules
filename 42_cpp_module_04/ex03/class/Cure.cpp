/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor42 <smontuor42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 23:45:33 by smontuor42        #+#    #+#             */
/*   Updated: 2024/09/08 23:46:59 by smontuor42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure")
{
	dbgprint(BOLDGREEN + getType(), "'s default constructor called");
}

Cure::Cure(const Cure &src) : AMateria(src)
{
	dbgprint(BOLDBLUE + getType(), "'s copy constructor called");
}

Cure::~Cure()
{
	dbgprint(BOLDRED + getType(), "'s destructor called");
}

Cure		&Cure::operator=(const Cure &rhs)
{
	AMateria::operator=(rhs);
	return *this;
}

AMateria	*Cure::clone() const
{
	return new Cure(*this);
}

void		Cure::use(ICharacter &target)
{
	print(BOLDWHITE , "\"* heals " + target.getName() + "'s wounds *\"");
}
