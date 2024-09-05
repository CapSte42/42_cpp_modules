/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:48:14 by smontuor          #+#    #+#             */
/*   Updated: 2024/09/05 10:44:49 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"
#include <iostream>

// Constructors
//--- Default Constructor
//--- Constructor Overload
//--- Copy Constructor
//--- Default Destructor
DiamondTrap::DiamondTrap() : ClapTrap("noNameDiamondTrap_clap_name"), ScavTrap(), FragTrap(), _name("noNameDiamondTrap")
{
	dbgPrint("Default DiamondTrap constructor called");
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	dbgPrint("DiamondTrap constructor called");
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(src), ScavTrap(src), FragTrap(src), _name(src._name)
{
	dbgPrint("DiamondTrap copy constructor called");
	_hitPoints = src._hitPoints;
	_energyPoints = src._energyPoints;
	_attackDamage = src._attackDamage;
}

DiamondTrap::~DiamondTrap()
{
	dbgPrint("DiamondTrap destructor called");
}

// Overload operator
//--- Assignation operator

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		FragTrap::operator=(other);
		ScavTrap::operator=(other);
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	dbgPrint("DiamondTrap assignation operator called");
	return *this;
}

// Set - Get
//--- Setters
//--- Getters
std::string DiamondTrap::getName(void) const
{
	return _name;
}

void DiamondTrap::setName(std::string name)
{
	_name = name;
}

// Public member functions
void DiamondTrap::whoAmI(void)
{
	if (amIOk())
		std::cout << "I am " << _name << " and my ClapTrap name is " << ClapTrap::getName() << std::endl;
}

void DiamondTrap::attack(std::string const &target)
{
	if (amIOk())
	{
		_energyPoints -= 1;
		ScavTrap::attack(target);
	}
}
