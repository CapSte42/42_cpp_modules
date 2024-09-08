/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor42 <smontuor42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 23:36:01 by smontuor42        #+#    #+#             */
/*   Updated: 2024/09/08 23:45:09 by smontuor42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
	public:

		Cure();
		Cure(const Cure &src);
		virtual ~Cure();

		Cure		&operator=(const Cure &rhs);

		AMateria	*clone() const;
		void		use(ICharacter &target);
};

#endif
