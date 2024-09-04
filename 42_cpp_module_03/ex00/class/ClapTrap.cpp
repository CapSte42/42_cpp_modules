/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:55:00 by smontuor          #+#    #+#             */
/*   Updated: 2024/09/03 21:20:46 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include <iostream>

// Constructors
//--- Default Constructor
//--- Constructor Overload
//--- Copy Constructor
//--- Default Destructor
ClapTrap::ClapTrap() : _name("NoName"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {dbgPrint("Default constructor called");}
ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {dbgPrint("Constructor overload called");}
ClapTrap::ClapTrap(const ClapTrap &other) : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage) {dbgPrint("Copy constructor called");}
ClapTrap::~ClapTrap() {dbgPrint("Default destructor called");}

// Overload operator
//--- Assignation operator
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	dbgPrint("Assignation operator called");
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
void ClapTrap::setName(std::string name) { _name = name; }
void ClapTrap::setHitPoints(unsigned int hitPoints) { _hitPoints = hitPoints; }
void ClapTrap::setEnergyPoints(unsigned int energyPoints) { _energyPoints = energyPoints; }
void ClapTrap::setAttackDamage(unsigned int attackDamage) { _attackDamage = attackDamage; }

std::string ClapTrap::getName() const { return (_name); }
unsigned int ClapTrap::getHitPoints() const { return (_hitPoints); }
unsigned int ClapTrap::getEnergyPoints() const { return (_energyPoints); }
unsigned int ClapTrap::getAttackDamage() const { return (_attackDamage); }

// Public member functions
//--- Actions functions
void ClapTrap::attack(std::string const &target)
{
	if (amIOk())
	{
		print(0, _attackDamage, _name, target);
		_energyPoints--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amIOk())
	{
		if (amount > _hitPoints)
			_hitPoints = 0;
		else
			_hitPoints -= amount;
		print(1, amount, _name);
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (amIOk())
	{
		_hitPoints += amount;
		_energyPoints--;
		print(2, amount, _name);
	}
}

// Other
//--- print {0: attack, 1: takeDamage, 2: beRepaired, default: print}
//--- debug print
//--- amIOk?
void ClapTrap::print(int action, unsigned int &value,const std::string &name, const std::string &target)
{
	switch (action)
	{
		case 0:
			std::cout << BOLD GREEN << name <<": YOU! " << target << "! This will hurt you more than it will hurt me! At least " << value << " points of damage!" << RESET << std::endl;
			break;
		case 1:
			std::cout << BOLD YELLOW << name << ": You fool! You think you can hurt me? I will take that " << value << " points of damage!" << RESET << std::endl;
			break;
		case 2:
			std::cout << BOLD BLUE << name <<": Let me get my s*it together! I will repair myself with " << value << " points!" << RESET << std::endl;
			break;
		case 3:
			std::cout << BOLD RED << name << ": *awkward silence*...some flies are flying around... " << name << " is dead... " << RESET << std::endl;
			break;
		case 4:
			std::cout << BOLD RED << name << ": I'm tired boss, I'm tired. I'm tired of being on the road, lonely as a sparrow in the rain. I'm tired of never having me a buddy to be with, to tell me where we's going to, coming from or why. Mostly, I'm tired of people being ugly to each other. I'm tired of all the pain I feel and hear in the world every day. There's too much of it. It's like pieces of glass in my head all the time. Can you understand?" << RESET << std::endl;
			break;
		default:
			std::cout << name << ": Ehi " << target << "What is he trying to do? I'm really confused, too tired or too dead to understand!" << std::endl;
			break;
	}
}

void	ClapTrap::dbgPrint(const std::string &msg)
{
	if (DEBUG)
		std::cout << BOLD RED "DEBUG: " << msg << RESET << std::endl;
}

bool ClapTrap::amIOk()
{
	if (_hitPoints < 1)
	{
		print(3, _energyPoints, _name);
		return (false);
	}
	if (_energyPoints < 1)
	{
		print(4, _energyPoints, _name);
		return (false);
	}
	return (true);
}
