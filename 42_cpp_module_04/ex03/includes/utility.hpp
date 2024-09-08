/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor42 <smontuor42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 20:17:56 by smontuor42        #+#    #+#             */
/*   Updated: 2024/09/08 23:23:35 by smontuor42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_HPP
# define UTILITY_HPP

# include <string>

# define BOLDRED		"\033[1;31m" // for destructor
# define BOLDGREEN		"\033[1;32m" // for default constructor
# define BOLDYELLOW		"\033[1;33m" // for generic debug
# define BOLDBLUE		"\033[1;34m" // for copy constructor
# define BOLDMAGENTA	"\033[1;35m"
# define BOLDCYAN		"\033[1;36m"
# define BOLDWHITE		"\033[1;37m" // for print actions
# define RESET			"\033[0m"

# ifndef DEBUG
#  define DEBUG 1
# endif

void	dbgprint(std::string color, std::string msg);
void	print(std::string color, std::string msg);

#endif
