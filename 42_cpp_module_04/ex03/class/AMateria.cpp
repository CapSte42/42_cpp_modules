/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor42 <smontuor42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 20:32:47 by smontuor42        #+#    #+#             */
/*   Updated: 2024/09/08 23:50:38 by smontuor42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"

AMateria::AMateria(std::string const &type) : _type(type)
{
	dbgprint(BOLDGREEN, "AMateria's default constructor called");
}

AMateria::AMateria(const AMateria &src) : _type(src._type)
{
	dbgprint(BOLDBLUE, "AMateria's copy constructor called");
}

AMateria::~AMateria()
{
	dbgprint(BOLDRED, "AMateria's destructor called");
}

AMateria	&AMateria::operator=(const AMateria &rhs)
{
	
	return *this;
}

std::string const	&AMateria::getType() const
{
	return _type;
}

void				AMateria::use(ICharacter &target)
{
	print(BOLDWHITE, " used by " + target.getName());
}
