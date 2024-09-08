/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor42 <smontuor42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:12:44 by smontuor42        #+#    #+#             */
/*   Updated: 2024/09/08 18:20:17 by smontuor42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:

		Brain	*_brain;

	public:

		Dog();
		Dog(const Dog &src);
		virtual ~Dog();

		Dog				&operator=(const Dog &rhs);

		virtual void	makeSound() const;

		Brain			*getBrain() const;
};

#endif
