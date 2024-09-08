/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor42 <smontuor42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 23:35:40 by smontuor42        #+#    #+#             */
/*   Updated: 2024/09/08 23:48:44 by smontuor42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
	public:

		Ice();
		Ice(const Ice &src);
		virtual ~Ice();

		Ice		&operator=(const Ice &rhs);

		AMateria	*clone() const;
		void		use(ICharacter &target);
};

#endif
