/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 10:40:55 by smontuor          #+#    #+#             */
/*   Updated: 2024/09/04 12:31:12 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
	private:
		std::string _name;

	public:
		// Default constructor
		Zombie();

		// Parameterized constructor
		Zombie(std::string name);

		// Destructor
		~Zombie();

		// Setter
		void setName(std::string name);

		// Member function
		void announce(void) const;
};

#endif
