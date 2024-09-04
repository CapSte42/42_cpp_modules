/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:55:11 by smontuor          #+#    #+#             */
/*   Updated: 2024/09/03 22:05:37 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"
#include <iostream>

// Constructors
//--- Default Constructor
//--- Constructor Overload
//--- Copy Constructor
//--- Default Destructor
ScavTrap::ScavTrap() : ClapTrap("NoNameScavTrap")
{
	dbgPrint("Default ScavTrap constructor called");
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	dbgPrint("ScavTrap Constructor overload called");
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other.getName())
{
	dbgPrint("ScavTrap Copy constructor called");
	_hitPoints = other.getHitPoints();
	_energyPoints = other.getEnergyPoints();
	_attackDamage = other.getAttackDamage();
}

ScavTrap::~ScavTrap()
{
	dbgPrint("Default ScavTrap destructor called");
}

// Overload operator
//--- Assignation operator
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	dbgPrint("ScavTrap Assignation operator called");
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
//--- Override attack
//--- guardGate
// Other inherited from ClapTrap
void ScavTrap::attack(std::string const &target)
{
	if (amIOk())
	{
		std::cout << ITALIC GREEN << _name <<": YOU! " << target << "! Take this! At least " << _attackDamage << " points of damage!" << RESET << std::endl;
		_energyPoints--;
	}
}

void ScavTrap::guardGate()
{
	if (amIOk())
		std::cout << ITALIC BLUE << _name << ": I'm the gatekeeper! I will guard this gate with my life!" << RESET << std::endl;
}
