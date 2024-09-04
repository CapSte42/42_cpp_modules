/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 10:23:33 by smontuor          #+#    #+#             */
/*   Updated: 2024/09/04 12:31:38 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Braiiiiiiinnnzzzz.hpp"
#include "../includes/ZombieHorde.hpp"

int main(void)
{
	int	N = 5;
	Zombie* horde = zombieHorde(N, BOLD_WHITE + "Horde" + RESET);

	if (!horde)
		return (1);
	for (int i = 0; i < N; i++)
		horde[i].announce();

	delete[] horde;

	return (0);
}
