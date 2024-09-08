/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor42 <smontuor42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:14:28 by smontuor42        #+#    #+#             */
/*   Updated: 2024/09/08 17:26:05 by smontuor42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat")
{
	print(BOLDGREEN + getType(), "'s default constructor called");
}

Cat::Cat(const Cat &src) : Animal(src)
{
	print(BOLDBLUE + getType(), "'s copy constructor called");
}

Cat::~Cat()
{
	print(BOLDRED + getType(), "'s destructor called");
}

Cat		&Cat::operator=(const Cat &rhs)
{
	Animal::operator=(rhs);
	return *this;
}

void	Cat::makeSound() const
{
	print(BOLDWHITE + getType(), ": Meows");
}
