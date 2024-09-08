/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor42 <smontuor42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 17:48:56 by smontuor42        #+#    #+#             */
/*   Updated: 2024/09/08 18:09:25 by smontuor42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain's default constructor called" << std::endl;
}

Brain::Brain(const Brain &src)
{
	*this = src;
	std::cout << "Brain's copy constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain's destructor called" << std::endl;
}

Brain	&Brain::operator=(const Brain &rhs)
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = rhs._ideas[i];
	return *this;
}

void	Brain::setIdea(int index, std::string idea)
{
	if (index < 0 || index >= 100)
	{
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	if (idea.empty())
	{
		std::cout << "Invalid idea" << std::endl;
		return ;
	}
	if (!_ideas[index].empty())
		std::cout << "Idea at index " << index << " overwritten" << std::endl;
	_ideas[index] = idea;
}

std::string	Brain::getIdea(int index) const
{
	if (index < 0 || index >= 100)
	{
		std::cout << "Invalid index" << std::endl;
		return "";
	}
	if (_ideas[index].empty())
	{
		std::cout << "No idea at index " << index << std::endl;
		return "";
	}
	return _ideas[index];
}

void	Brain::printIdea(int index) const
{
	if (index < 0 || index >= 100)
	{
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	if (_ideas[index].empty())
	{
		std::cout << "No idea at index " << index << std::endl;
		return ;
	}
	std::cout << "Idea at index " << index << ": " << _ideas[index] << std::endl;
}

void	Brain::printAllIdeas() const
{
	for (int i = 0; i < 100; i++)
	{
		if (!_ideas[i].empty())
			std::cout << "Idea at index " << i << ": " << _ideas[i] << std::endl;
	}
}
