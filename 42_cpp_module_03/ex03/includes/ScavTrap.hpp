/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:44:40 by smontuor          #+#    #+#             */
/*   Updated: 2024/09/03 22:57:09 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ScavTrap_HPP
# define ScavTrap_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
// Constructors
//--- Default Constructor
//--- Constructor Overload
//--- Copy Constructor
//--- Default Destructor
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &other);
		~ScavTrap();

// Overload operator
//--- Assignation operator
		ScavTrap &operator=(const ScavTrap &other);

// Set - Get
//--- Setters
//--- Getters
// inherited from ClapTrap

// Public member functions
//--- Override attack
//--- guardGate
// Other inherited from ClapTrap
		void attack(std::string const &target);
		void guardGate();
};

#endif // ScavTrap_HPP
