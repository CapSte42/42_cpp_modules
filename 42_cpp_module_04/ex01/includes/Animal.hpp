/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor42 <smontuor42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:39:04 by smontuor          #+#    #+#             */
/*   Updated: 2024/09/08 17:21:12 by smontuor42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

# ifndef DEBUG
#  define DEBUG 1
# endif

# define BOLDRED "\033[1m\033[31m"
# define BOLDGREEN "\033[1m\033[32m"
# define BOLDYELLOW "\033[1m\033[33m"
# define BOLDBLUE "\033[1m\033[34m"
# define BOLDWHITE "\033[1m\033[37m"
# define RESET "\033[0m"

class Animal
{
	protected:

		std::string _type;

	public:

		Animal();
		Animal(std::string type);
		Animal(const Animal &src);
		virtual ~Animal();

		Animal			&operator=(const Animal &rhs);

		std::string		getType() const;
		void			setType(std::string type);

		void			dbgprint(std::string type, std::string msg) const;
		void			print(std::string type, std::string msg) const;
		virtual void	makeSound() const;
};

#endif
