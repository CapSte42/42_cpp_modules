/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:09:43 by smontuor          #+#    #+#             */
/*   Updated: 2024/09/04 12:33:23 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"
#include "../includes/HumanA.hpp"
#include "../includes/HumanB.hpp"
#include <iostream>

void	scenario1()
{
	std::cout << "Scenario 1: HumanA with weapon changing type" << std::endl;
	Weapon sword("sharp sword");
	HumanA arthur("Arthur", sword);
	arthur.attack();
	sword.setType("legendary Excalibur");
	arthur.attack();
	std::cout << std::endl;
}

void	scenario2()
{
	std::cout << "Scenario 2: HumanB starts unarmed, gets a weapon, changes weapon type" << std::endl;
	HumanB lancelot("Lancelot");
	lancelot.attack();

	Weapon lance("long lance");
	lancelot.setWeapon(lance);
	lancelot.attack();

	lance.setType("golden lance");
	lancelot.attack();
	std::cout << std::endl;
}

void	scenario3()
{
	std::cout << "Scenario 3: HumanA and HumanB sharing the same weapon" << std::endl;
	Weapon axe("battle axe");
	HumanA thor("Thor", axe);
	HumanB loki("Loki");
	loki.setWeapon(axe);

	thor.attack();
	loki.attack();

	axe.setType("enchanted axe");
	thor.attack();
	loki.attack();
	std::cout << std::endl;
}

void	scenario4()
{
	std::cout << "Scenario 4: HumanB tries to attack without a weapon" << std::endl;
	HumanB aragorn("Aragorn");
	aragorn.attack();
	std::cout << std::endl;
}

void	scenario5()
{
	std::cout << "Scenario 5: HumanB sets and changes weapons multiple times" << std::endl;
	Weapon bow("wooden bow");
	Weapon dagger("small dagger");
	HumanB legolas("Legolas");

	legolas.setWeapon(bow);
	legolas.attack();

	legolas.setWeapon(dagger);
	legolas.attack();

	bow.setType("elven bow");
	legolas.setWeapon(bow);
	legolas.attack();
	std::cout << std::endl;
}

void	scenario6()
{
	std::cout << "Scenario 6: Weapon is destroyed before HumanB tries to attack" << std::endl;
	HumanB gollum("Gollum");

	{
		Weapon ring("the One Ring");
		gollum.setWeapon(ring);
		gollum.attack();
	}

	gollum.attack();
	std::cout << std::endl;
}

void	subjectScenario()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
}

int	main()
{
	scenario1();
	scenario2();
	scenario3();
	scenario4();
	scenario5();
	scenario6();
	subjectScenario();

	return (0);
}
