/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 12:38:25 by smontuor          #+#    #+#             */
/*   Updated: 2024/09/04 12:31:46 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Braiiiiiiinnnzzzz.hpp"
#include <iostream>

Zombie*	newZombie( std::string name )
{
	if (name.empty())
		name = "Infamous";
	Zombie*	zombie = new Zombie();

	zombie->setName(name);
	std::cout << "Zombie " << name
			  << " raised from the dead!"
			  << " And steps out of the heap!"
			  << std::endl;
	return (zombie);
}
