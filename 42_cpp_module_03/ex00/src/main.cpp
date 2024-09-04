/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:55:16 by smontuor          #+#    #+#             */
/*   Updated: 2024/09/03 22:07:03 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

int main()
{
	{
		ClapTrap claptrap1("Claptrap1");
		ClapTrap claptrap2 = claptrap1;

		claptrap2.setName("Claptrap2");

		claptrap1.setAttackDamage(1);
		for (int i = 0; i < 10; i++)
		{
			claptrap1.attack(claptrap2.getName());
			claptrap2.takeDamage(claptrap1.getAttackDamage());
		}
		claptrap2.beRepaired(10);
		claptrap1.attack(claptrap2.getName());
		claptrap2.takeDamage(claptrap1.getAttackDamage());
	}
}
