/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 09:53:01 by smontuor          #+#    #+#             */
/*   Updated: 2024/09/04 12:32:33 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <string>

class HumanA
{
	private:

		std::string	_name;
		Weapon		&_weapon;

	public:

		HumanA(const std::string &name, Weapon &weapon);
		void	attack() const;
};

#endif
