/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor42 <smontuor42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:14:15 by smontuor42        #+#    #+#             */
/*   Updated: 2024/09/08 18:41:05 by smontuor42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog")
{
	_brain = new Brain();
	print(BOLDGREEN + getType(), "'s default constructor called");
}

Dog::Dog(const Dog &src) : Animal(src)
{
	_brain = new Brain(*src._brain);
	print(BOLDBLUE + getType(), "'s copy constructor called");
}

Dog::~Dog()
{
	delete _brain;
	print(BOLDRED + getType(), "'s destructor called");
}

Dog &Dog::operator=(const Dog &rhs)
{
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		delete _brain;
		_brain = new Brain(*rhs.getBrain());
	}
	return *this;
}

void	Dog::makeSound() const
{
	print(BOLDWHITE + getType(), ": Bau bau");
}

Brain	*Dog::getBrain() const
{
	return _brain;
}
