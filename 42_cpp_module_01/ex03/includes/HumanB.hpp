/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:09:54 by smontuor          #+#    #+#             */
/*   Updated: 2024/09/04 12:32:39 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <string>

class HumanB
{
	private:

		std::string	_name;
		Weapon		*_weapon;

	public:

		HumanB(const std::string &name);

		void	setWeapon(Weapon &weapon);
		void	attack() const;
};

#endif
