/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:55:16 by smontuor          #+#    #+#             */
/*   Updated: 2024/09/03 22:10:30 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"

int main()
{
	// {
	// 	ClapTrap claptrap1("Claptrap1");
	// 	ClapTrap claptrap2 = claptrap1;

	// 	claptrap2.setName("Claptrap2");

	// 	claptrap1.setAttackDamage(1);
	// 	for (int i = 0; i < 10; i++)
	// 	{
	// 		claptrap1.attack(claptrap2.getName());
	// 		claptrap2.takeDamage(claptrap1.getAttackDamage());
	// 	}
	// 	claptrap2.beRepaired(10);
	// 	claptrap1.attack(claptrap2.getName());
	// 	claptrap2.takeDamage(claptrap1.getAttackDamage());
	// }

	{
		ScavTrap scavtrap1("Scavtrap1");
		ScavTrap scavtrap2 = scavtrap1;

		scavtrap2.setName("Scavtrap2");

		for (int i = 0; i < 10; i++)
		{
			scavtrap1.attack(scavtrap2.getName());
			scavtrap2.takeDamage(scavtrap1.getAttackDamage());
			if (i % 3 == 0)
				scavtrap2.beRepaired(10);
		}
		scavtrap2.beRepaired(10);
		scavtrap1.attack(scavtrap2.getName());
		scavtrap2.takeDamage(scavtrap1.getAttackDamage());
		scavtrap1.guardGate();
	}
}
