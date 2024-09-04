/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 21:59:45 by smontuor          #+#    #+#             */
/*   Updated: 2024/09/04 12:34:48 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl
{
private:

	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

public:

	void complain(std::string level);

};

#endif // HARL_HPP
