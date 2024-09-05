/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:39:04 by smontuor          #+#    #+#             */
/*   Updated: 2024/09/05 10:30:33 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>

class Animal
{
	protected:

		std::string _type;

	public:

		Animal();
		Animal(std::string type);
		Animal(const Animal &src);
		virtual ~Animal();

		Animal &operator=(const Animal &rhs);

		std::string getType() const;
		void setType(std::string type);
		virtual void makeSound() const;
};

#endif
