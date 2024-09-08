/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor42 <smontuor42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:14:28 by smontuor42        #+#    #+#             */
/*   Updated: 2024/09/08 18:42:03 by smontuor42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat")
{
	_brain = new Brain();
	print(BOLDGREEN + getType(), "'s default constructor called");
}

Cat::Cat(const Cat &src) : Animal(src)
{
	_brain = new Brain(*src._brain);
	print(BOLDBLUE + getType(), "'s copy constructor called");
}

Cat::~Cat()
{
	delete _brain;
	print(BOLDRED + getType(), "'s destructor called");
}

Cat &Cat::operator=(const Cat &rhs)
{
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		delete _brain;
		_brain = new Brain(*rhs.getBrain());
	}
	return *this;
}

void	Cat::makeSound() const
{
	print(BOLDWHITE + getType(), ": Meows");
}

Brain	*Cat::getBrain() const
{
	return _brain;
}
