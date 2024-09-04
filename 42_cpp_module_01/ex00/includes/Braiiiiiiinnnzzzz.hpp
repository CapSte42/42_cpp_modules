/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Braiiiiiiinnnzzzz.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 12:23:14 by smontuor          #+#    #+#             */
/*   Updated: 2024/08/04 21:23:54 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIIIIIIINNNNZZZZ_HPP
# define BRAIIIIIIINNNNZZZZ_HPP

# include "Zombie.hpp"

const std::string	RESET			= "\033[0m";
const std::string	BOLD_RED		= "\033[1;31m";
const std::string	BOLD_GREEN		= "\033[1;32m";
const std::string	BOLD_YELLOW		= "\033[1;33m";
const std::string	BOLD_BLUE		= "\033[1;34m";
const std::string	BOLD_MAGENTA	= "\033[1;35m";
const std::string	BOLD_CYAN		= "\033[1;36m";
const std::string	BOLD_WHITE		= "\033[1;37m";

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

#endif
