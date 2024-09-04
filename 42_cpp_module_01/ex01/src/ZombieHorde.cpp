/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 21:46:08 by smontuor          #+#    #+#             */
/*   Updated: 2024/09/04 12:32:02 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ZombieHorde.hpp"
#include <sstream>

std::string	intToString(int n)
{
	std::stringstream ss;
	ss << n;
	return (ss.str());
}

Zombie*	zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return (NULL);
	if (name.empty())
		name = "Tricky";

	Zombie* horde = new Zombie[N];

	for (int i = 0; i < N; i++)
		horde[i].setName(name + "_" + intToString(i));

	return (horde);
}
