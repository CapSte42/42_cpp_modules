/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor42 <smontuor42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:00:16 by smontuor42        #+#    #+#             */
/*   Updated: 2024/09/08 18:29:15 by smontuor42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:

		Brain	*_brain;

	public:

		Cat();
		Cat(const Cat &src);
		virtual ~Cat();

		Cat				&operator=(const Cat &rhs);

		virtual void	makeSound() const;

		Brain			*getBrain() const;
};

#endif
