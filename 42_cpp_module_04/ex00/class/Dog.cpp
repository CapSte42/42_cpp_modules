/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor42 <smontuor42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:14:15 by smontuor42        #+#    #+#             */
/*   Updated: 2024/09/08 16:10:44 by smontuor42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog") {}

Dog::Dog(const Dog &src) : Animal(src) {}

Dog::~Dog() {}

Dog		&Dog::operator=(const Dog &rhs)
{
	Animal::operator=(rhs);
	return *this;
}

void	Dog::makeSound() const
{
	print(BOLDWHITE + getType(), ": Bau bau");
}
