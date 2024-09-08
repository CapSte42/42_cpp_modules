/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor42 <smontuor42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 20:26:34 by smontuor42        #+#    #+#             */
/*   Updated: 2024/09/09 00:17:10 by smontuor42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "utility.hpp"
# include "ICharacter.hpp"
# include <string>

class ICharacter;

class AMateria
{
	protected:

		std::string	_type;

	public:

		AMateria(std::string const &type);
		AMateria(const AMateria &src);
		virtual ~AMateria();

		AMateria	&operator=(const AMateria &rhs);

		std::string const	&getType() const;

		virtual AMateria	*clone() const = 0;
		virtual void		use(ICharacter &target);
};

#endif
