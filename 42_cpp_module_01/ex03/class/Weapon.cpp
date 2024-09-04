/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 09:44:28 by smontuor          #+#    #+#             */
/*   Updated: 2024/09/04 12:33:03 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

// Constructor
Weapon::Weapon(const std::string &type) : _type(type) {}

// Setter & Getter
const	std::string &Weapon::getType() const { return _type; }
void	Weapon::setType(const std::string &type) { _type = type; }
