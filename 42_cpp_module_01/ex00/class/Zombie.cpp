/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 12:25:16 by smontuor          #+#    #+#             */
/*   Updated: 2024/09/04 12:30:09 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"
#include <iostream>

// Default constructor
Zombie::Zombie() : _name("\0") {}

// Parameterized constructor
Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << "Zombie " << this->_name
			  << " raised from the dead!"
			  << " And runs from the stack!"
			  << std::endl;
}

// Destructor
Zombie::~Zombie() { std::cout << "Zombie " << this->_name << " died again!" << std::endl; }

// Setter
void Zombie::setName(std::string name) { this->_name = name; }

// Member function
void Zombie::announce(void) const {	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;}
