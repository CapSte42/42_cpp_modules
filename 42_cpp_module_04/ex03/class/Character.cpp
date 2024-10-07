/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 00:10:18 by smontuor42        #+#    #+#             */
/*   Updated: 2024/09/19 14:16:41 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"
#include <iostream>
#include <sstream>


Character::Character(std::string const &name) : _name(name)
{
	for (int i = 0; i < 4; ++i)
		_inventory[i] = NULL;
	dbgprint(BOLDGREEN, _name + "'s constructor called");
}

Character::Character(const Character &src) : _name(src._name)
{
	for (int i = 0; i < 4; ++i)
	{
		if (src._inventory[i])
			_inventory[i] = src._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
	dbgprint(BOLDBLUE, _name + "'s copy constructor called");
}

Character::~Character()
{
	for (int i = 0; i < 4; ++i)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
	dbgprint(BOLDRED, _name + "'s destructor called");
}

Character &Character::operator=(const Character &rhs)
{
	if (this != &rhs)
	{
		_name = rhs._name;
		for (int i = 0; i < 4; ++i)
		{
			if (_inventory[i])
				delete _inventory[i];
			if (rhs._inventory[i])
				_inventory[i] = rhs._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	return *this;
}

std::string const &Character::getName() const
{
	return _name;
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; ++i)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			print(BOLDCYAN, _name + " equips " + m->getType());
			return;
		}
	}
	print(BOLDYELLOW, _name + "'s inventory is full");
}


void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && _inventory[idx] != NULL)
	{
		_inventory[idx] = NULL;
		std::stringstream ss;
		ss << idx;
		print(BOLDCYAN, _name + " unequips materia at index " + ss.str());
	}
	else
	{
		print(BOLDYELLOW, _name + " tried to unequip an invalid index");
	}
}


void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && _inventory[idx] != NULL)
	{
		_inventory[idx]->use(target);
	}
	else
	{
		print(BOLDYELLOW, _name + " tried to use an invalid index");
	}
}
