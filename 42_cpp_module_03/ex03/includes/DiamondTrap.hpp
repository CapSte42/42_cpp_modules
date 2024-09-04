/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:41:59 by smontuor          #+#    #+#             */
/*   Updated: 2024/09/03 23:18:38 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string _name;

	public:
// Constructors
//--- Default Constructor
//--- Constructor Overload
//--- Copy Constructor
//--- Default Destructor
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &src);
		~DiamondTrap();

// Overload operator
//--- Assignation operator
		DiamondTrap &operator=(const DiamondTrap &other);

// Set - Get
//--- Setters
//--- Getters
// others inherited from ScavTrap and FragTrap
		std::string getName(void) const;
		void setName(std::string name);

// Public member functions
		void whoAmI(void);
		void attack(std::string const &target);
};

#endif
