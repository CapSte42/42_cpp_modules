/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:16:03 by smontuor          #+#    #+#             */
/*   Updated: 2024/09/03 22:18:14 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"
#include <iostream>

// Constructors
//--- Default Constructor
//--- Constructor Overload
//--- Copy Constructor
//--- Default Destructor
FragTrap::FragTrap() : ClapTrap("NoNameFragTrap")
{
	dbgPrint("Default FragTrap constructor called");
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	dbgPrint("FragTrap Constructor overload called");
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other.getName())
{
	dbgPrint("FragTrap Copy constructor called");
	_hitPoints = other.getHitPoints();
	_energyPoints = other.getEnergyPoints();
	_attackDamage = other.getAttackDamage();
}

FragTrap::~FragTrap()
{
	dbgPrint("Default FragTrap destructor called");
}

// Overload operator
//--- Assignation operator
FragTrap &FragTrap::operator=(const FragTrap &other)
{
	dbgPrint("FragTrap Assignation operator called");
	if (this == &other)
		return (*this);
	_name = other.getName();
	_hitPoints = other.getHitPoints();
	_energyPoints = other.getEnergyPoints();
	_attackDamage = other.getAttackDamage();
	return (*this);
}

// Set - Get
//--- Setters
//--- Getters
// inherited from ClapTrap

// Public member functions
void FragTrap::highFivesGuys(void)
{
	if (amIOk())
		std::cout << ITALIC YELLOW << _name << ": Gimme five guys! Please, stop fighting!" << RESET << std::endl;
}
