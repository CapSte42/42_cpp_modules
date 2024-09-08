/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor42 <smontuor42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 00:12:32 by smontuor42        #+#    #+#             */
/*   Updated: 2024/09/09 00:16:47 by smontuor42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; ++i)
		_templates[i] = NULL;
	dbgprint(BOLDGREEN, "MateriaSource default constructor called");
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	for (int i = 0; i < 4; ++i)
	{
		if (src._templates[i])
			_templates[i] = src._templates[i]->clone();
		else
			_templates[i] = NULL;
	}
	dbgprint(BOLDBLUE, "MateriaSource copy constructor called");
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; ++i)
	{
		if (_templates[i])
			delete _templates[i];
	}
	dbgprint(BOLDRED, "MateriaSource destructor called");
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 4; ++i)
		{
			if (_templates[i])
				delete _templates[i];
			if (rhs._templates[i])
				_templates[i] = rhs._templates[i]->clone();
			else
				_templates[i] = NULL;
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; ++i)
	{
		if (_templates[i] == NULL)
		{
			_templates[i] = m;
			dbgprint(BOLDCYAN, "Learned new materia: " + m->getType());
			return;
		}
	}
	dbgprint(BOLDYELLOW, "Cannot learn more Materias, storage is full");
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (_templates[i] && _templates[i]->getType() == type)
			return _templates[i]->clone();
	}
	dbgprint(BOLDYELLOW, "Unknown Materia type: " + type);
	return NULL;
}
