/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor42 <smontuor42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 17:47:44 by smontuor42        #+#    #+#             */
/*   Updated: 2024/09/08 17:55:00 by smontuor42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain
{
	private:

		std::string _ideas[100];

	public:

		Brain();
		Brain(const Brain &src);
		~Brain();

		Brain	&operator=(const Brain &rhs);

		void	setIdea(int index, std::string idea);
		std::string	getIdea(int index) const;

		void	printIdea(int index) const;
		void	printAllIdeas() const;
};

#endif
