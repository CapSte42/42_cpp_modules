/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor42 <smontuor42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:14:15 by smontuor42        #+#    #+#             */
/*   Updated: 2024/09/08 17:26:43 by smontuor42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog")
{
	print(BOLDGREEN + getType(), "'s default constructor called");
}

Dog::Dog(const Dog &src) : Animal(src)
{
	print(BOLDBLUE + getType(), "'s copy constructor called");
}

Dog::~Dog()
{
	print(BOLDRED + getType(), "'s destructor called");
}

Dog		&Dog::operator=(const Dog &rhs)
{
	Animal::operator=(rhs);
	return *this;
}

void	Dog::makeSound() const
{
	print(BOLDWHITE + getType(), ": Bau bau");
}
