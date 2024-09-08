/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor42 <smontuor42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:00:16 by smontuor42        #+#    #+#             */
/*   Updated: 2024/09/08 14:11:59 by smontuor42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	public:

		Cat();
		Cat(const Cat &src);
		virtual ~Cat();

		Cat				&operator=(const Cat &rhs);

		virtual void	makeSound() const;
};

#endif
