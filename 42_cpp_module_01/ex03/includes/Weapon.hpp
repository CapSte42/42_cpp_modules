/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 09:28:39 by smontuor          #+#    #+#             */
/*   Updated: 2024/08/28 07:35:18 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
	private:

		std::string	_type;

	public:

		Weapon(const std::string &type);

//		Setter & Getter
		const std::string	&getType() const;
		void		setType(const std::string &type);
};

#endif
