/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 10:23:33 by smontuor          #+#    #+#             */
/*   Updated: 2024/09/04 12:30:16 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Braiiiiiiinnnzzzz.hpp"

int main(void)
{
	Zombie*	zombie1 = newZombie(BOLD_RED + "Foo" + RESET);
	Zombie*	zombie2 = newZombie(BOLD_GREEN + "Bar" + RESET);
	Zombie*	zombie3 = newZombie(BOLD_YELLOW + "Baz" + RESET);

	zombie1->announce();
	zombie2->announce();
	zombie3->announce();

	randomChump(BOLD_BLUE + "Qux" + RESET);
	randomChump(BOLD_MAGENTA + "Quux" + RESET);
	randomChump(BOLD_BLUE + "Corge" + RESET);

	delete zombie1;
	delete zombie2;
	delete zombie3;

	return (0);
}
