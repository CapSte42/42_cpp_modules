/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 12:38:33 by smontuor          #+#    #+#             */
/*   Updated: 2024/09/04 12:31:51 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Braiiiiiiinnnzzzz.hpp"

void	randomChump( std::string name )
{
	if (name.empty())
		name = "Infamous";
	Zombie(name).announce();
}
